/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:30:10 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/13 11:29:35 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	if (write(1, "rr\n", 3) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}

void	reverse(t_list **stk)
{
	*stk = (*stk)->prev;
}

void	reverse_a(t_list **stk_a, t_list **stk_b)
{
	reverse(stk_a);
	if (write(1, "rra\n", 4) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}

void	reverse_b(t_list **stk_a, t_list **stk_b)
{
	reverse(stk_b);
	if (write(1, "rrb\n", 4) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}

void	reverse_both(t_list **stk_a, t_list **stk_b)
{
	reverse(stk_a);
	reverse(stk_b);
	if (write(1, "rrr\n", 4) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}
