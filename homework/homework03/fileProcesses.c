#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main()
{
	int fileDescriptor;

	pid_t returnedValue = fork();
	if (returnedValue < 0)
	{
		perror("error forking");
		return -1;
	}
	else if (returnedValue == 0)
	{
		if (open("/etc/passwd", O_RDONLY) < 0)
		{
			perror("error opening /etc/passwd");
			return -1;
		}
		fileDescriptor = dup2(open("/etc/passwd", O_RDONLY), STDIN_FILENO);
		if (fileDescriptor < 0)
		{
			perror("error creating a copy of file descriptor");
		}

		close(open("/etc/passwd", O_RDONLY));
		execlp("tr", "tr", "a-z", "A-Z", NULL); // ps with option letter l
		perror("error executing ps");
		return -1;
	}
	else
	{
		if (waitpid(returnedValue, 0, 0) < 0)
		{
			perror("error waiting for child");
			return -1;
		}
	}
}