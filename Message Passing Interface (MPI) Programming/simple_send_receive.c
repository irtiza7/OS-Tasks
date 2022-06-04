#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);
    
    int my_index;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_index);

    if(my_index == 0) {
        int receive_value;
        int source = 1;
        int tag = 10;
        MPI_Status status;

        MPI_Recv(&receive_value, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
        printf("%d\n", receive_value);

    } else if(my_index == 1){
        int send_value = 5;
        int tag = 10;
        int destination = 0;

        MPI_Send(&send_value, 1, MPI_INT, destination, tag, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}