/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:26:11 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/16 18:50:41 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	chr_to_bin(char ch, int pid)
{
	int	i;
	int	octet;

	i = 0;
	octet = 0;
	while (i < 8)
	{
		octet = (ch >> (7 - i)) & 1;
		if (octet == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

static void	error_check( int argc, char *argv)
{
	while (*argv)
	{
		if (!ft_isdigit(*argv++) || argc != 3)
		{
			write(STDOUT_FILENO, "\033[1;31m", 7);
			write(STDOUT_FILENO, "\n(Wrong arguments format) ", 26);
			write(STDOUT_FILENO, "\033[0m", 4);
			write(STDOUT_FILENO, "Enter parameters correctly:\n\n\t\t\t", 32);
			write(STDOUT_FILENO, "./client.c <PID> \"message\"\n\n\n", 29);
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	error_check(argc, argv[1]);
	while (*argv[2])
		chr_to_bin(*argv[2]++, ft_atoi(argv[1]));
	return (0);
}
