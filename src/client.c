#include "../include/minitalk.h"

static void str_to_bin(const char *str, int pid)
{
	int		i;
	char	octet;
	char	res[LENGTH];

	ft_strlcpy(res, str, ft_strlen(str) + 1);
	ft_strlcat(res, "\n\0", ft_strlen(res) + 3);
	printf("\"%s\"", res);
    while (*str)
	{
		i = 7;
        while (i >= 0)
		{
			octet = *str;
			if (octet & (1 << i--))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(2720);
		}
        str++;
    }
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		str_to_bin(argv[2], ft_atoi(argv[1]));
	else
	{
		printf("\n\nError (wrong format): Enter parameters correctly:\n\n");
		printf("\t\t\t./client.c <PID> \"message\"\n\n\n");
	}
	return (0);
}
