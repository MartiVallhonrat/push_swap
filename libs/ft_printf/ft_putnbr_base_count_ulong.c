/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_count_long.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:48:44 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/19 13:24:30 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_base_ulong(char *base)
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

void	get_char_numbers_ulong(char *base, unsigned long nbr,
			unsigned long base_size, int *count)
{
	char	c;
	int		temp;

	if (nbr >= base_size)
	{
		get_char_numbers_ulong(base, (nbr / base_size), base_size, count);
		if (*count == -1)
			return ;
		get_char_numbers_ulong(base, (nbr % base_size), base_size, count);
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

int	ft_putnbr_base_count_ulong(void *void_nbr, char *base)
{
	unsigned long	base_size;
	unsigned long	nbr;
	int				count;

	nbr = (unsigned long)void_nbr;
	base_size = 0;
	count = 0;
	count += write(1, "0x", 2);
	if (count == -1)
		return (-1);
	while (base[base_size] != '\0')
		base_size++;
	if (return_base_ulong(base) == 1 && base_size > 1)
		get_char_numbers_ulong(base, nbr, base_size, &count);
	return (count);
}

/*int	main(void)
{
	unsigned int	count = 0;

	ft_putnbr_base_count_uns(&count, "0123456789ABCDEF", count);
	printf("counter: %d\n", count);
	return (0);
}*/
