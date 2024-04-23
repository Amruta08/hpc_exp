#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10 // Define the upper limit of the range

int main(int argc, char** argv) {
    int rank, size;
    int start, end; // Range for each process
    int i, cube;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    start = rank * (N / size) + 1;
    end = (rank + 1) * (N / size);

    if (rank == size - 1) {
        end = N;
    }

    for (i = start; i <= end; i++) {
        cube = i * i * i;
        printf("Process %d: Cube of %d is %d\n", rank, i, cube);
    }

    MPI_Finalize();
    return 0;
}
