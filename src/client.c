/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:26:11 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/24 12:17:29 by dchrysov         ###   ########.fr       */
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

/**
 * @brief Checks if parameters are valid
 */
static void	error_check( int argc, char *argv)
{
	if (argc == 1)
	{
		ft_printf("\033[1;31m\n(Wrong argument format) ");
		ft_printf("\033[0mEnter parameters as:\n\n\t\t\t");
		ft_printf("./client.c <PID> \"message\"\n\n\n");
		exit(0);
	}
	else
	{
		while (*argv)
		{
			if (!ft_isdigit(*argv++) || argc != 3)
			{
				ft_printf("\033[1;31m\n(Wrong argument format) ");
				ft_printf("\033[0mEnter parameters as:\n\n\t\t\t");
				ft_printf("./client.c <PID> \"message\"\n\n\n");
				exit(0);
			}
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
