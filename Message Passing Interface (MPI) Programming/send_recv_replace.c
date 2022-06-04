#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int my_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int value = 10 + my_id;
    int tag = 1;

    MPI_Status status;

    MPI_Sendrecv_replace(
        &value, 1, MPI_INT, ((my_id + 1) % num_procs), tag, 
        ((my_id - 1 + num_procs) % num_procs), tag,
        MPI_COMM_WORLD, &status);

    printf("This is process: %d, I received %d from process %d\n", my_id, value, status.MPI_SOURCE);

    MPI_Finalize();
}