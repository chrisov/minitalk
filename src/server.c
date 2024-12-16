#include "../include/minitalk.h"

volatile sig_atomic_t bit = -1;

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
}

// static void	signal_handler_s2(int sig)
// {
// 	(void)sig;
// 	bit = 0;
// }

static void server(void)
{
	char	octet;
	int		bit_count;
	// char	str[LENGTH];

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
}

int	main(void)
{
	printf("\nServer is running. PID: %d\n", getpid());
	printf("------------------------------------------------\n\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	server();
	return (0);
}