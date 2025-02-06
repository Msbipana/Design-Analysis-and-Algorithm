#include <stdio.h>
#include <time.h>

// Function for Bubble Sort
void bubbleSort(int array[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j+1]
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
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

    // Perform Bubble Sort
    bubbleSort(array, size);

    end = clock();

    // Calculate the execution time
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    printArray(array, size);

    printf("Execution time: %f seconds\n", executionTime);

    return 0;
}

