#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int my_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int value = 10;
    int broadcaster = 0;

    // MPI_Bcast(&value, 1, MPI_INT, broadcaster, MPI_COMM_WORLD);

    if(my_id == broadcaster) {
        value = 5;
        MPI_Bcast(&value, 1, MPI_INT, broadcaster, MPI_COMM_WORLD);
    } else {
        MPI_Bcast(&value, 1, MPI_INT, broadcaster, MPI_COMM_WORLD);
    }

    if (my_id != broadcaster) {
        printf("This is process: %d, I received %d from broadcaster.\n", my_id, value);
    }

    MPI_Finalize();
}