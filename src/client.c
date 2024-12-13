#include "../include/minitalk.h"

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if ( argc == 3)
	{
		strncpy(msg, argv[2], LENGTH);
		pid = atoi(argv[1]);
		
	}

	return (0);
}