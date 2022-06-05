#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int my_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    MPI_Request request;
    MPI_Status status;

    if(my_id == 0) {
        int send_value = 10 + my_id;
        MPI_Isend(&send_value, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &request);

    } else if(my_id == 1) {
        int recv_value = 0;
        MPI_Irecv(&recv_value, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, &status);
        printf("I am process: %d, and I got %d from 0.\n", my_id, recv_value);
    } 

    MPI_Finalize();
}