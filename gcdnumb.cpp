#include <stdio.h>
#include <time.h>

// Naive method to calculate GCD
int gcd_naive(int a, int b) {
    int i;
    for (i = a < b ? a : b; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1; // In case of no common divisors other than 1
}

// Euclidean algorithm to calculate GCD
int gcd_euclidean(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_euclidean(b, a % b);
}

int main() {
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    // Naive GCD
    clock_t start_time_naive = clock();
    int result_naive = gcd_naive(a, b);
    clock_t end_time_naive = clock();
    double elapsed_time_naive = (double)(end_time_naive - start_time_naive) / CLOCKS_PER_SEC;

    printf("GCD of %d and %d (naive): %d\n", a, b, result_naive);
    printf("Computational time (naive): %f seconds\n", elapsed_time_naive);

    // Euclidean GCD
    clock_t start_time_euclidean = clock();
    int result_euclidean = gcd_euclidean(a, b);
    clock_t end_time_euclidean = clock();
    double elapsed_time_euclidean = (double)(end_time_euclidean - start_time_euclidean) / CLOCKS_PER_SEC;

    printf("GCD of %d and %d (Euclidean): %d\n", a, b, result_euclidean);
    printf("Computational time (Euclidean): %f seconds\n", elapsed_time_euclidean);

    return 0;
}

