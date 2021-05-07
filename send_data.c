#include <mpi.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // check if number of processors are 2
    if (world_size != 2){
	MPI_Abort(MPI_COMM_WORLD, 66);
    }

    // Find out the producer
    bool producer=false;
    if (world_rank == 0) producer=true;

    // Send and receive some data
    int dummy_data=555;
    if (producer){
	// syntax MPI_SEND(*pointer to data, count, datatype, dest, tag, communicator)
	MPI_Send(&dummy_data, 1, MPI_INT, 1, 1351, MPI_COMM_WORLD);
    } else {
	// syntax MPI_recv(*pointer to data destination, count, datatype, source, tag, communicator, status)
    	MPI_Status status;
	MPI_Recv(&dummy_data, 1, MPI_INT, 0, 1351, MPI_COMM_WORLD, &status);
    }

    // Print the received data
    if (!producer) printf("Received data %d from processor 0\n", dummy_data);
    // Finalize the MPI environment.
    MPI_Finalize();
}
