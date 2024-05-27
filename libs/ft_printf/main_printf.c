/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:48:26 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/19 12:10:18 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_percent(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

int	ft_printf(const	char *s, ...)
{
	int		i;
	int		count;
	int		temp;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		temp = count;
		if (is_percent(s[i]))
		{
			if (!check_placeholder(s[++i], &count, args))
				return (0);
		}
		else
			count += write(1, &s[i], 1);
		i++;
		if (count < temp)
			return (-1);
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int	test = 16;
	printf("ft_printf result: %d\n", ft_printf("%x\n", test));
	return (0);
}*/
