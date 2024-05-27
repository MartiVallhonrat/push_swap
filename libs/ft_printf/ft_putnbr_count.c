/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:02:48 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/19 15:09:57 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_count_getchar(long nbr, int *count)
{
	int		temp;

	if (nbr >= 10)
	{
		ft_putnbr_count_getchar(nbr / 10, count);
		if (*count == -1)
			return ;
		ft_putnbr_count_getchar(nbr % 10, count);
		if (*count == -1)
			return ;
	}
	else
	{
		temp = *count;
		*count += ft_putchar_count((int)nbr + '0');
		if (*count < temp)
		{
			*count = -1;
			return ;
		}
	}
}

int	ft_putnbr_count(int n)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = (long)n;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		if (count == -1)
			return (-1);
		ft_putnbr_count_getchar(nbr * (-1), &count);
	}
	else
		ft_putnbr_count_getchar(nbr, &count);
	return (count);
}

/*int	main(void)
{
	int	count;

	count = 0;
	ft_putnbr_count(32, &count);
	printf("result: %d\n", count);
	return (0);
}*/
