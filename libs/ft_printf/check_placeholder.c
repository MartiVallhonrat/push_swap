/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_placeholder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:12:22 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/19 16:11:53 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	check_placeholder(char c, int *count, va_list args)
{
	if (!check_valid(c))
		return (0);
	if (c == '%')
		*count += write(1, "%", 1);
	else if (c == 'c')
		*count += ft_putchar_count(va_arg(args, int));
	else if (c == 's')
		*count += ft_putstr_count(va_arg(args, char *));
	else if (c == 'p')
		*count += ft_putnbr_base_count_ulong(va_arg(args, void *),
				"0123456789abcdef");
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr_count(va_arg(args, int));
	else if (c == 'u')
		*count += ft_putnbr_count_uns(va_arg(args, unsigned int));
	else if (c == 'x')
		*count += ft_putnbr_base_count_uns(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		*count += ft_putnbr_base_count_uns(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	return (1);
}
