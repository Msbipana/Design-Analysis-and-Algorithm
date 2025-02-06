#include <stdio.h>
#include <time.h>

// Function for Insertion Sort
void insertionSort(int array[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        // Move elements of array[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size; // Size of the array

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size]; // Input array

    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Original array: ");
    printArray(array, size);

    // Measure the execution time
    clock_t start, end;
    start = clock();

    // Perform Insertion Sort
    insertionSort(array, size);

    end = clock();

    // Calculate the execution time
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(array, size);

    printf("Execution time: %f seconds\n", executionTime);

    return 0;
}

