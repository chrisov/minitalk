#include "../include/minitalk.h"

volatile sig_atomic_t bit = -1;

static void	signal_handler_s1(int sig)
{
	(void)sig;
	bit = 1;
}

static void	signal_handler_s2(int sig)
{
	(void)sig;
	bit = 0;
}

static void server(void)
{
	char	octet;
	int		bit_count;

	octet = 0;
	bit_count = 0;
	while (1)
	{
		pause();
		if (bit != -1)
		{
			octet = (octet << 1) | bit;
			bit_count++;
			if (bit_count == 8)
			{
				write(STDOUT_FILENO, &octet, 1);
				octet = 0;
				bit_count = 0;
			}
			bit = -1;
		}
	}
	printf("\n");
}

int	main(void)
{
	printf("\nServer is running. PID: %d\n", getpid());
	printf("------------------------------------------------\n\n");
	signal(SIGUSR1, signal_handler_s1);
	signal(SIGUSR2, signal_handler_s2);
	server();
	return (0);
}