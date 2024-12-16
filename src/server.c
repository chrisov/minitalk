/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:26:39 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/16 17:47:19 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	server(int sig)
{
	static int	octet;
	static int	bit_count;

	if (sig == SIGUSR1)
		octet = (octet << 1) | 1;
	else if (sig == SIGUSR2)
		octet = (octet << 1) | 0;
	bit_count++;
	if (bit_count == 8)
	{
		if (write(STDOUT_FILENO, &octet, 1) == -1)
			exit (1);
		octet = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	printf("\nServer is running. PID: %d\n", getpid());
	printf("------------------------------------------------\n\n");
	signal(SIGUSR1, server);
	signal(SIGUSR2, server);
	while (1)
		pause();
	return (0);
}