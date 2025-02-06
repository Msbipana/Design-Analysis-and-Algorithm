#include <stdio.h>
#include <time.h>

// Function for Selection Sort
void selectionSort(int array[], int size) {
    int i, j, minIndex, temp;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
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

    // Perform Selection Sort
    selectionSort(array, size);

    end = clock();

    // Calculate the execution time
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(array, size);

    printf("Execution time: %f seconds\n", executionTime);

    return 0;
}

