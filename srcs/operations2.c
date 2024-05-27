/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:08:20 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/13 11:29:09 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list **dest, t_list **src)
{
	push(dest, src);
	if (write(1, "pa\n", 3) == -1)
	{
		ft_lstclear(dest);
		ft_lstclear(src);
		exit(0);
	}
}

void	push_b(t_list **dest, t_list **src)
{
	push(dest, src);
	if (write(1, "pb\n", 3) == -1)
	{
		ft_lstclear(dest);
		ft_lstclear(src);
		exit(0);
	}
}

void	rotate(t_list **stk)
{
	*stk = (*stk)->next;
}

void	rotate_a(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_a);
	if (write(1, "ra\n", 3) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}

void	rotate_b(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_b);
	if (write(1, "rb\n", 3) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}
