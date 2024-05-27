/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:31:50 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/14 20:07:00 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	max_top(t_list **stk_a, t_list **stk_b)
{
	while ((*stk_b)->content != get_max(stk_b)->content)
	{
		if (get_max(stk_b)->above == 1)
			rotate_b(stk_a, stk_b);
		else
			reverse_b(stk_a, stk_b);
	}
}

void	move_back(t_list **stk_a, t_list **stk_b)
{
	int		rem;

	rem = ft_lstlen(stk_a);
	while (*stk_b != NULL || is_sorted(stk_a) == 0)
	{
		if ((*stk_b == NULL
				|| (*stk_a)->prev->content > (*stk_b)->content) && rem > 0)
		{
			reverse_a(stk_a, stk_b);
			rem--;
		}
		else
		{
			push_a(stk_a, stk_b);
		}
	}
}
