/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:28:35 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/14 20:07:50 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	start(t_list **stk_a, t_list **stk_b)
{
	if (ft_lstlen(stk_a) > 3)
	{
		push_b(stk_b, stk_a);
		push_b(stk_b, stk_a);
	}
}

void	ft_sort(t_list **stk_a, t_list **stk_b)
{
	if (is_sorted(stk_a))
		return ;
	start(stk_a, stk_b);
	set_stacks(stk_a, stk_b);
	do_sort(stk_a, stk_b);
}
