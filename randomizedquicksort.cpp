#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Randomized partition function
int randomizedPartition(int arr[], int low, int high) {
    // Choose a random pivot index between low and high
    int randomPivotIndex = low + rand() % (high - low + 1);

    // Swap the random pivot element with the last element
    swap(&arr[randomPivotIndex], &arr[high]);

    // Call the partition function as usual
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized Quick Sort function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partition index
        int pi = randomizedPartition(arr, low, high);

        // Recursively sort the subarrays
        randomizedQuickSort(arr, low, pi - 1);   // Left of the pivot
        randomizedQuickSort(arr, pi + 1, high);  // Right of the pivot
    }
}

int main() {
    int n;

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Ask user to enter the elements of the array
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Record the start time
    clock_t start = clock();

    // Perform randomized quick sort
    randomizedQuickSort(arr, 0, n - 1);

    // Record the end time
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the computation time
    printf("Time taken to sort the array using Randomized Quick Sort: %f seconds\n", time_taken);

    return 0;
}

