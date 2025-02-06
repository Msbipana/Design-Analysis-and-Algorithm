#include <stdio.h>
#include <time.h>

// Function to calculate factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Start timer
    clock_t start_time = clock();

    // Calculate factorial
    long long result = factorial(n);

    // Stop timer
    clock_t end_time = clock();

    // Calculate elapsed time
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Factorial of %d is: %lld\n", n, result);
    printf("Computational time: %f seconds\n", elapsed_time);

    return 0;
}

