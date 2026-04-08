						; insertion_sort.asm
						; x86-64 NASM - Linux
section .data
    unsorted     db "Unsortiertes Array: ", 10
    unsorted_len equ $ - unsorted

    sorted       db "Sortiertes Array: ", 10
    sorted_len   equ $ - sorted

    space        db " "
    nl           db 10

    array        dd 12, 11, 13, 5, 6          ; das zu sortierende Array

section .bss
    num_buffer   resb 20                       ; Puffer für Zahl-zu-String-Umwandlung

section .text
    global _start

_start:
    ; === Unsortiertes Array ausgeben ===
    mov rax, 1
    mov rdi, 1
    mov rsi, unsorted
    mov rdx, unsorted_len
    syscall

    call print_array

    ; === Sortieren ===
    call insertion_sort

    ; === Sortiertes Array ausgeben ===
    mov rax, 1
    mov rdi, 1
    mov rsi, sorted
    mov rdx, sorted_len
    syscall

    call print_array

    ; === Programm beenden ===
    mov rax, 60
    xor rdi, rdi
    syscall

; =============================================
; print_array: Gibt das Array mit Leerzeichen aus
; =============================================
print_array:
    xor r15, r15                ; r15 = Index i = 0
.loop:
    cmp r15, 5
    je .done

    mov edi, [array + r15*4]    ; Zahl laden (32-Bit)
    call print_number

    ; Leerzeichen ausgeben
    mov rax, 1
    mov rdi, 1
    mov rsi, space
    mov rdx, 1
    syscall

    inc r15
    jmp .loop
.done:
    ; Zeilenumbruch
    mov rax, 1
    mov rdi, 1
    mov rsi, nl
    mov rdx, 1
    syscall
    ret

; =============================================
; print_number: Gibt eine positive Zahl (in RDI) aus
; =============================================
print_number:
    push rbp
    mov rbp, rsp

    mov rax, rdi                ; Zahl in RAX
    lea r8, [num_buffer + 19]   ; Zeiger ans Ende des Puffers
    mov r9, 10
    xor rcx, rcx                ; Länge = 0

    cmp rax, 0
    jne .div_loop

    ; Sonderfall 0
    mov byte [num_buffer], '0'
    lea rsi, [num_buffer]
    mov rcx, 1
    jmp .write

.div_loop:
    xor rdx, rdx
    div r9
    add dl, '0'
    mov [r8], dl
    dec r8
    inc rcx
    test rax, rax
    jnz .div_loop

    inc r8                      ; r8 zeigt jetzt auf die erste Ziffer
    mov rsi, r8

.write:
    mov rax, 1                  ; sys_write
    mov rdi, 1
    mov rdx, rcx                ; Länge
    syscall

    pop rbp
    ret

; =============================================
; insertion_sort: Implementierung des Insertion-Sort
; =============================================
insertion_sort:
    mov r12, 1                  ; i = 1
.outer:
    cmp r12, 5
    jge .done

    mov r13d, [array + r12*4]   ; key = arr[i]
    mov r14, r12
    dec r14                     ; j = i - 1

.inner:
    cmp r14, 0
    jl .insert

    mov eax, [array + r14*4]
    cmp eax, r13d
    jle .insert                 ; arr[j] <= key → fertig

    ; Verschieben: arr[j+1] = arr[j]
    mov [array + r14*4 + 4], eax
    dec r14
    jmp .inner

.insert:
    ; key an die richtige Stelle
    mov [array + r14*4 + 4], r13d

    inc r12
    jmp .outer

.done:
    ret


; ====================================================
; nasm -f elf64 insertion_sort.asm -o insertion_sort.o
; ld insertion_sort.o -o insertion_sort
; ./insertion_sort
; ====================================================

