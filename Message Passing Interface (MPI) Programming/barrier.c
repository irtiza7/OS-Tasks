#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int my_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    if(my_id == 0) {
        printf("This is process: %d\n", my_id);
        MPI_Barrier(MPI_COMM_WORLD);
    } else if(my_id == 1) {
        printf("This is process: %d\n", my_id);
        sleep(5);
        MPI_Barrier(MPI_COMM_WORLD);
    } else if(my_id == 2) {
        printf("This is process: %d\n", my_id);
        sleep(10);
    }

    // MPI_Barrier(MPI_COMM_WORLD);
    printf("This is process: %d, and i have crossed barrier.\n", my_id);

    MPI_Finalize();
}