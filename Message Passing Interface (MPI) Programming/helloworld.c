#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
    int num_procs;
    int my_index;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_index);

    printf("Num of Processes: %d, My Index: %d\n", num_procs, my_index);

    MPI_Finalize();
}