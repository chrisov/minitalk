/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:28:19 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/12 14:11:07 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	const char	*str = "Hello World \t3!";
//
// 	printf("\nTest string: %s\n", str);
// 	while (*str)
// 	{
// 		if (ft_isprint(*str) == 0)
// 		{
// 			printf("The argument contains non printable chars.\n");
// 			return (0);
// 		}
// 		str++;
// 	}
// 	printf("The argument contains only printable chars.\n");
// 	return (0);
// }