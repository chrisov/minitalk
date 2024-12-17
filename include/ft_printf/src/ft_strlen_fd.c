/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchrysov <dchrysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:03:59 by dchrysov          #+#    #+#             */
/*   Updated: 2024/12/17 14:57:32 by dchrysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlen_fd(const char str[])
{
	const char		*ptr;
	unsigned long	len;

	ptr = str;
	len = 0;
	while (*ptr)
	{
		len++;
		ptr++;
	}
	return (len);
}
