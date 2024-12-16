/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:26:11 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/16 17:41:48 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	chr_to_bin(char ch, int pid)
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
		usleep(200);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i++]))
			{
				write(STDOUT_FILENO, "Wrong PID format. Use a PID of the following format\n", 49);
				exit(1);
			}
		}
		while (*argv[2])
		{
			chr_to_bin(*argv[2], ft_atoi(argv[1]));
			argv[2]++;
		}
	}
	else
	{
		printf("\n\n\033[1;31mError\033[0m (wrong format): Enter parameters correctly:\n\n");
		printf("\t\t\t./client.c <PID> \"message\"\n\n\n");
	}
	return (0);
}
