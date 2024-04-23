#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads = omp_get_max_threads();
    printf("Number of threads: %d\n", num_threads);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Hello, world from thread %d\n", thread_id);
    }

    return 0;
}

//gcc -o hello -fopenmp hello.c
// ./hello