#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int my_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int send_value = 10 + my_id;
    int receive_value;
    int tag = 1;

    MPI_Status status;

    MPI_Sendrecv(
        &send_value, 1, MPI_INT, ((my_id + 1) % num_procs), tag, 
        &receive_value, 1, MPI_INT, ((my_id - 1 + num_procs) % num_procs), tag,
        MPI_COMM_WORLD, &status
    );

    printf("This is process: %d, I received %d from process %d with tag = %d\n", my_id, receive_value, status.MPI_SOURCE, status.MPI_TAG);

    MPI_Finalize();
}