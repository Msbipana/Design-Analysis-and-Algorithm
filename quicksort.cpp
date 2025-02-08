#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Partition function for quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot is chosen as the last element
    int i = (low - 1);      // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);  // Return the partition index
}

// Quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index, arr[pi] is now at the correct position
        int pi = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pi - 1);  // Left of the pivot
        quickSort(arr, pi + 1, high); // Right of the pivot
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

    // Perform quick sort
    quickSort(arr, 0, n - 1);

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
    printf("Time taken to sort the array using Quick Sort: %f seconds\n", time_taken);

    return 0;
}

