#include <stdio.h>
#include <omp.h>

#define NUM_STEPS 1000000

int main() {
    double pi = 0.0;
    double step = 1.0 / NUM_STEPS;

    #pragma omp parallel
    {
        double x;
        double sum = 0.0;

        #pragma omp for
        for (int i = 0; i < NUM_STEPS; i++) {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }

        #pragma omp critical
        {
            pi += sum * step;
        }
    }

    double area = pi * pi;
    printf("Value of PI/Area of Circle: %f\n", area);

    return 0;
}

//gcc -o pi -fopenmp pi.c
//./pi

