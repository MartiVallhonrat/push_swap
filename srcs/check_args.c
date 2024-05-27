/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:17:53 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/16 15:49:27 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_nan(int argc, char *argv[])
{
	int		i;
	char	*str;

	while (--argc)
	{
		i = 0;
		str = argv[argc];
		while (str[i])
		{
			if (!((str[i] >= '0' && str[i] <= '9')
					|| str[i] == '-' || str[i] == '+' || str[i] == '\t' || str[i] == ' '))
				return (0);
			if (i != 0 && (str[i] == '-' || str[i] == '+') && (str[i - 1] >= '0' && str[i - 1] <= '9'))
				return (0);
			if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_repeat(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
