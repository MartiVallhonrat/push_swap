/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count_uns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:39:36 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/19 16:00:29 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_count_uns_getchar(unsigned int n, int *count)
{
	int	temp;

	if (n >= 10)
	{
		ft_putnbr_count_uns_getchar(n / 10, count);
		if (*count == -1)
			return ;
		ft_putnbr_count_uns_getchar(n % 10, count);
		if (*count == -1)
			return ;
	}
	else
	{
		temp = *count;
		*count += ft_putchar_count(n + '0');
		if (*count < temp)
		{
			*count = -1;
			return ;
		}
	}
}

int	ft_putnbr_count_uns(unsigned int n)
{
	int	count;

	count = 0;
	ft_putnbr_count_uns_getchar(n, &count);
	return (count);
}
