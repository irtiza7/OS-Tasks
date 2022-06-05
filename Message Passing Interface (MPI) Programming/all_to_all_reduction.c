#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc,&argv);

	int procs;
	MPI_Comm_size(MPI_COMM_WORLD, &procs);
	
	int my_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

	int send_value, recv_value;
	int tag = 1;

	send_value = my_id;
	
	MPI_Allreduce(&send_value, &recv_value, tag, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

	// MPI_Barrier(MPI_COMM_WORLD);
	printf("I'm process: %d, Result of Reduction is: %d.\n", my_id, recv_value);

	MPI_Finalize();
}
