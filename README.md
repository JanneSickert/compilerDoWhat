## Ohne Librarys (Handgeschrieben)
------------------------------------------------------------------------------
-rwxr-xr-x  1 januar          januar          522.5 KB         8. Apr 21:07   executable_linux_binary        insertionSort_rust_kompilat          27   Zeilen Quellcode
-rwxr-xr-x  1 januar          januar          15.7 KB          8. Apr 21:06   executable_linux_binary        insertionSort_c_bin                  40   Zeilen Quellcode       
-rwxr-xr-x  1 januar          januar          9.4 KB           8. Apr 21:16   executable_linux_binary        insertion_sort_x86_assembly          155  Zeilen Quellcode


## Mit standart Linux Kernel Librarys(ASM generiert)
------------------------------------------------------------------------------
-rwxr-xr-x  2 januar          januar          4051 KB          8. Apr 21:42   executable_linux_binary        lll_rust_compilat                    344  Zeilen Quellcode
-rwxr-xr-x  1 januar          januar          22.3 KB          8. Apr 20:56   executable_linux_binary        lll_c_compilat                       568  Zeilen Quellcode
-rw-r--r--  1 januar          januar          -------          8. Apr 21:28   Assembly                       lll_source.asm                       2626 Zeilen Quellcode

------------------------------------------------------------------------------

# Assembly < C <<< Rust
Warum benötigt ein Rust kompilat egal ob nur reiner code mit rustc compiliert oder mit cargo immer etwa 185 mal mehr binär oder maschienencode als ein C kompilat mit ähnlichen aufbau und libraris. Und was hat C noch an bischen overhead das Assembly 1,6 mal so klein ist. Das verrückte ist nicht C vs. asm das war zu erwarten aber was ist mit Rust

----

Der Hauptgrund für den riesigen Unterschied bei Rust (ca. 33× beim Insertion-Sort-Beispiel und ~185× beim „lll“-Programm) liegt am Linken der Standardbibliothek – und das ist nicht nur „Rust ist halt bloated“, sondern ein fundamentales Design-Entscheidung.1. Rust vs. C: Statisches vs. dynamisches Linken der BibliothekenC (gcc/clang):
Die Standard-Bibliothek (libc / glibc) wird standardmäßig dynamisch gelinkt. Das heißt: Dein insertionSort_c_bin (15,7 KB) oder lll_c_compilat (22,3 KB) enthält nur deinen eigenen Code + einen winzigen Startup-Teil (crt0.o).
Der ganze schwere Kram (printf, malloc, I/O, String-Funktionen, Threading usw.) liegt in /lib/x86_64-linux-gnu/libc.so.6 und wird erst zur Laufzeit vom Linux-Loader nachgeladen. Deshalb bleibt die Binary winzig, egal wie viel „Library-Code“ du theoretisch nutzt.
Rust (rustc oder cargo):
Die Rust-Standardbibliothek (std) wird standardmäßig statisch in deine Binary reingelinkt. Es gibt kein libstd.so auf deinem System, das alle Rust-Programme gemeinsam nutzen könnten (Rust hat kein stabiles ABI für std).
Deshalb landet der gesamte benötigte Code aus libstd (inkl. Panic-Handler, Formatierungs-Code, Allocator-Logik, Stack-Unwinding, Backtrace-Unterstützung usw.) direkt in deiner Executable.
Selbst wenn du nur einen simplen insertionSort schreibst und main() hast, zieht Rust Teile von std (z. B. für std::env::args, Array-Handling, Panic-Handling) mit rein – und das sind Hunderte KB kompilierten Rust-Codes.

----

Das erklärt exakt deine Zahlen:Insertion-Sort Rust 522,5 KB vs. C 15,7 KB → Rust bringt ~500 KB libstd-Rust-Code mit.
lll Rust 4.051 KB vs. C 22,3 KB → Das „lll“-Programm nutzt offenbar mehr von std (mehr I/O, Collections, Error-Handling etc.), deshalb explodiert der statisch gelinkte Anteil auf ~4 MB.

----

Cargo vs. reines rustc macht fast keinen Unterschied, weil das Problem nicht Cargo ist, sondern genau diese statische Verlinkung von std.2. Warum ist C noch 1,6× größer als dein handgeschriebenes Assembly?Das ist der erwartete kleine „C-Overhead“:Der C-Compiler (gcc) fügt automatisch CRT-Startup-Code (C Runtime) hinzu:_start-Einstiegspunkt
Stack-Setup, argc/argv-Übergabe
Aufruf von __libc_start_main
Initialisierung von libc (z. B. für stdio, locale, etc.)
Aufruf von main() und danach exit()

----

Das sind ein paar KB statisch gelinkter Code aus crt0.o + libc-Init. Dein reines x86-Assembly (insertion_sort_x86_assembly 9,4 KB) hat das nicht – du schreibst direkt den minimalen _start, machst Syscalls und fertig. Deshalb ist Assembly ~60 % der C-Größe. Vollkommen normal und erwartet.3. Was macht Rust noch extra „teuer“?Neben dem statischen Linken kommen noch ein paar Rust-spezifische Dinge dazu (die C nicht hat):Panic-Unwinding + Backtraces (standardmäßig aktiv) → extra Code für Stack-Entwirrung.
Monomorphisierung von Generics (z. B. Vec<T> für jeden Typ einzeln) → bei komplexeren Programmen mehr Code-Duplizierung.
Debug-Symbole + Metadaten (auch in Release oft noch drin, bis man stripppt).
Rusts eigene Runtime (lang_start, global allocator etc.).

----

Kurzer Exkurs: Man kann Rust auch klein machenWenn du willst, kannst du Rust-Binaries auf 10–20 KB runterdrücken (ähnlich C):cargo build --release
strip --strip-all
In Cargo.toml: panic = "abort" + LTO
-C prefer-dynamic (dann wird std dynamisch gelinkt – aber die Binary ist dann an eine spezifische Rust-Version gebunden)
Oder komplett #![no_std] + #![no_main] + eigenes _start (wie in Embedded/ASM).

----

Aber standardmäßig priorisiert Rust Portabilität, Sicherheit und „it just works“ statt minimale Binary-Größe – genau deswegen ist es größer als C.Zusammengefasst:
C „leiht“ sich die Library vom Betriebssystem (dynamisch).
Rust trägt seine Library immer mit sich (statisch).
Deshalb der Faktor 185× bei deinem lll-Programm. Das ist kein Bug, sondern die direkte Konsequenz aus „Rust hat kein shared libstd.so“.


