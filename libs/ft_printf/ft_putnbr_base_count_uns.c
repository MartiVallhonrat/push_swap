/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:32:25 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/19 16:15:05 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_base_uns(char *base)
{
	int	right_base;
	int	i;
	int	j;

	right_base = 1;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+'
			|| !(base[i] >= 32 && base[i] <= 126))
			right_base = 0;
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				right_base = 0;
			j++;
		}
		i++;
	}
	return (right_base);
}

void	get_char_numbers_uns(char *base, unsigned int nbr,
			unsigned int base_size, int *count)
{
	char	c;
	int		temp;

	if (nbr >= base_size)
	{
		get_char_numbers_uns(base, (nbr / base_size), base_size, count);
		if (*count == -1)
			return ;
		get_char_numbers_uns(base, (nbr % base_size), base_size, count);
		if (*count == -1)
			return ;
	}
	else
	{
		c = base[nbr];
		temp = *count;
		*count += write(1, &c, 1);
		if (*count < temp)
		{
			*count = -1;
			return ;
		}
	}
}

int	ft_putnbr_base_count_uns(unsigned int nbr, char *base)
{
	int				count;
	unsigned int	base_size;

	count = 0;
	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	if (return_base_uns(base) == 1 && base_size > 1)
		get_char_numbers_uns(base, nbr, base_size, &count);
	return (count);
}
