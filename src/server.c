#include "../include/minitalk.h"

int	main(void)
{
	__pid_t	pid;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	while (1)
		pause();
	printf("Exit");
	return (0);
}