#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
	clock_t t;
	t = clock();

	if (argc != 2)
	{
		perror("Usage: ");
		return -1;
	}

	int fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		perror(argv[1]);
		return -1;
	}

	struct stat info;
	if (fstat(fd_in, &info) < 0)
	{
		perror("Error stating input file.");
		return -1;
	}
	void* addr_in = mmap(0, info.st_size, PROT_READ, MAP_SHARED, fd_in, 0);
	if (addr_in == MAP_FAILED)
	{
		perror("Error mapping input file.");
		return -1;
	}

	if (memchr(addr_in, 'X', info.st_size))
	{

		printf("X is in the file.\n");
	}
	else
		printf("X is not in the file.\n");

	t = clock() - t;
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	printf("Execution Time: %f\n", timeTaken);
	return 0;
}