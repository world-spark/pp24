#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv)
{
	int rank, size, tag = 1;
	int senddata, recvdata;
	MPI_Status status;
	MPI_Init(&argc, &argv);				  /*MPI的初始化函数*/
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); /*该进程编号*/
	MPI_Comm_size(MPI_COMM_WORLD, &size); /*总进程数目*/
	if (rank == 0)
	{
		senddata = 9999;
		MPI_Send(&senddata, 1, MPI_INT, 1, tag, MPI_COMM_WORLD); /*发送数据到进程1*/
	}
	if (rank == 1)
		MPI_Recv(&recvdata, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
	/*从进程0接收数据*/
	MPI_Finalize(); /*MPI的结束函数*/
	return (0);
}
