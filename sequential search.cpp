#include <stdio.h>
#include <time.h>

// Function for sequential search
int sequentialSearch(int array[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == key) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int size = 5; // Size of the array
    int array[] = {1, 2, 3, 4, 5}; // Input array
    int key; // Key to search for

    printf("Input array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    // Measure the execution time
    clock_t start, end;
    start = clock();

    // Perform the sequential search
    int result = sequentialSearch(array, size, key);

    end = clock();

    // Calculate the execution time
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Key %d found at index %d.\n", key, result);
    } else {
        printf("Key %d not found.\n", key);
    }

    printf("Execution time: %f seconds\n", executionTime);

    return 0;
}

