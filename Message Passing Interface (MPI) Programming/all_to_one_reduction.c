#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc,&argv);

	int procs;
	MPI_Comm_size(MPI_COMM_WORLD, &procs);
	
	int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	int sendbuf, recvbuf;
	int tag = 1;
	int reduction_target_process = 0;

	sendbuf = my_rank;
	
	MPI_Reduce(&sendbuf, &recvbuf, tag, MPI_INT, MPI_SUM, reduction_target_process, MPI_COMM_WORLD);

	if(my_rank == reduction_target) {
		printf("I'm process: %d, Result of Reduction is: %d.\n", my_rank, recvbuf);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	printf("This is process: %d and recv buffer: %d.\n", my_rank, recvbuf);

	MPI_Finalize();
}
