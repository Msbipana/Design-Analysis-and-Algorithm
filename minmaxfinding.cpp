#include <stdio.h>
#include <time.h>

// Function to find the minimum and maximum in an array
void findMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min)
            *min = arr[i];
        if (arr[i] > *max)
            *max = arr[i];
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

    int min, max;

    // Record the start time
    clock_t start = clock();

    // Call the function to find min and max
    findMinMax(arr, n, &min, &max);

    // Record the end time
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output the results
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    printf("Time taken to find min and max: %f seconds\n", time_taken);

    return 0;
}

