#include <stdio.h>
#include <time.h>

// Recursive function to calculate Fibonacci
long long fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative function to calculate Fibonacci
long long fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }

    long long a = 0, b = 1, result = 0;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Recursive Fibonacci
    clock_t start_time_recursive = clock();
    long long result_recursive = fibonacci_recursive(n);
    clock_t end_time_recursive = clock();
    double elapsed_time_recursive = (double)(end_time_recursive - start_time_recursive) / CLOCKS_PER_SEC;

    printf("Fibonacci of %d (recursive): %lld\n", n, result_recursive);
    printf("Computational time (recursive): %f seconds\n", elapsed_time_recursive);

    // Iterative Fibonacci
    clock_t start_time_iterative = clock();
    long long result_iterative = fibonacci_iterative(n);
    clock_t end_time_iterative = clock();
    double elapsed_time_iterative = (double)(end_time_iterative - start_time_iterative) / CLOCKS_PER_SEC;

    printf("Fibonacci of %d (iterative): %lld\n", n, result_iterative);
    printf("Computational time (iterative): %f seconds\n", elapsed_time_iterative);

    return 0;
}

