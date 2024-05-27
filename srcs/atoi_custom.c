/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_custom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:12:04 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/14 19:36:29 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi_lo(char *str)
{
	long	res;
	long	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n'
			|| *str == '\t'
			|| *str == '\v' || *str == '\f'
			|| *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9' && res <= 2147483648)
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	res = res * negative;
	return (res);
}
