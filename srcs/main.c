/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:58:21 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/16 15:41:43 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	throw_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stk_a;
	t_list	*stk_b;

	if (argc == 1)
		return (1);
	stk_a = get_args(argc, argv);
	if (!stk_a)
		return (throw_error());
	stk_b = NULL;
	ft_sort(&stk_a, &stk_b);
	ft_lstclear(&stk_a);
	ft_lstclear(&stk_b);
	return (0);
}
