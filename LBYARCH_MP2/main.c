//Kyle Patrick Roland M Francisco
//Luis Rafayel Jaime
//SS1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Assembly kernel prototype
extern void stencil_1d(int n, double* X, double* Y);

// Function to perform the 1-D stencil operation in C
void stencil_sol(int n, double* X, double* Y) {
    for (int i = 3; i < n - 3; ++i) {
        Y[i - 3] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
    }
}

// Function to display the first ten elements of a vector
void display_first_ten(const char* name, int n, double* vector) {
    printf("First ten elements of vector %s: ", name);
    for (int i = 0; i < n && i < 10; ++i) {
        printf("%.2f ", vector[i]);
    }
    printf("\n");
}

int main() {
    int min_exponent = 20;
    int max_exponent = 30; 

    srand((unsigned int)time(NULL));


    double* X = NULL;
    double* Y = NULL;
    // Generate 30 sets of random values
    for (int i = 0; i < 30; ++i) {
        int n = 1 << (rand() % (max_exponent - min_exponent + 1)) + min_exponent;

        

        if (n >= 3) {
            X = (double*)malloc(n * sizeof(double));
            Y = (double*)malloc((n - 3) * sizeof(double));
        }
        else {
            printf("Vector size too small\n");
            return 1;
        }

        if (X == NULL || Y == NULL) {
            printf("Memory allocation failed\n");
            if (X) free(X); 
            if (Y) free(Y); 
            return 1;
        }

        for (int j = 0; j < 10; ++j) {
            X[j] = (double)(rand() % 100);
        }

        // Initialize the rest of X with consecutive values
        for (int j = 10; j < n; ++j) {
            X[j] = (double)j + 1;
        }

        // Display the first ten elements of X before the stencil operation
        display_first_ten("X", n, X);

        clock_t start, end;
        double cpu_time_used;

        start = clock();

        // 1-D stencil operation in C
        stencil_sol(n, X, Y);

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Display the first ten elements of Y after the stencil operation (C)
        display_first_ten("Y (C)", n - 3, Y);
        printf("Time taken for C stencil operation with n = %d (seconds): %f\n", n, cpu_time_used);

        start = clock();

        // 1-D stencil operation in assembly
        stencil_1d(n, X, Y);

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Display the first ten elements of Y after the stencil operation (assembly)
        display_first_ten("Y (Assembly)", n - 3, Y);
        printf("Time taken for Assembly stencil operation with n = %d (seconds): %f\n\n\n", n, cpu_time_used);

        // Free allocated memory
        free(X);    
        free(Y);

    }

   
    return 0;
}
