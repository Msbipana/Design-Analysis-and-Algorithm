#include <stdio.h>
#include <time.h>

// Binary search function
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If the target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;
        // If the target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Target is not found
    return -1;
}

int main() {
    int n, target;

    // Ask user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Ask user to enter the elements of the array
    printf("Enter %d sorted elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the target element
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Record the start time
    clock_t start = clock();

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, target);

    // Record the end time
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output the result of the search
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    // Print the computation time
    printf("Time taken for binary search: %f seconds\n", time_taken);

    return 0;
}

