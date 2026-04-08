#include <stdio.h>

// Die Insertion Sort Funktion
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; // Das Element, das einsortiert werden soll
        j = i - 1;

        /* Verschiebe Elemente, die größer als 'key' sind, 
           um eine Position nach rechts */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Setze das 'key' Element an die gefundene Lücke
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sortiertes Array: \n");
    printArray(arr, n);

    return 0;
}

