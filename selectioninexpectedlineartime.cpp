#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quickselect
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quickselect algorithm
int quickselect(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = low + rand() % (high - low + 1);  // Randomly pick a pivot
    swap(&arr[pivotIndex], &arr[high]);  // Swap with the last element
    
    // Partition the array around the pivot
    int pivotIndexAfterPartition = partition(arr, low, high);
    
    if (k == pivotIndexAfterPartition) {
        return arr[k];
    } else if (k < pivotIndexAfterPartition) {
        return quickselect(arr, low, pivotIndexAfterPartition - 1, k);
    } else {
        return quickselect(arr, pivotIndexAfterPartition + 1, high, k);
    }
}

int main() {
    int n, k;

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Ask user to enter the elements of the array
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask user for the position of the element to find (0-based index)
    printf("Enter the value of k (0-based index) to find the k-th smallest element: ");
    scanf("%d", &k);

    // Record the start time
    clock_t start = clock();

    // Perform quickselect to find the k-th smallest element
    int result = quickselect(arr, 0, n - 1, k);

    // Record the end time
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output the result and the computation time
    printf("The %d-th smallest element is: %d\n", k, result);
    printf("Time taken to find the %d-th smallest element using Quickselect: %f seconds\n", k, time_taken);

    return 0;
}

