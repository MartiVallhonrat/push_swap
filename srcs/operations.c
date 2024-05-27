/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:15 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/14 13:13:37 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stk)
{
	int	tmp;

	tmp = (*stk)->content;
	(*stk)->content = (*stk)->next->content;
	(*stk)->next->content = tmp;
}

void	swap_a(t_list **stk_a, t_list **stk_b)
{
	swap(stk_a);
	if (write(1, "sa\n", 3) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}

void	swap_b(t_list **stk_a, t_list **stk_b)
{
	swap(stk_b);
	if (write(1, "sb\n", 3) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}

void	swap_both(t_list **stk_a, t_list **stk_b)
{
	swap(stk_a);
	swap(stk_b);
	if (write(1, "ss\n", 3) == -1)
	{
		ft_lstclear(stk_a);
		ft_lstclear(stk_b);
		exit(0);
	}
}

void	push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (*src)
	{
		(*src)->next->prev = (*src)->prev;
		(*src)->prev->next = (*src)->next;
		if (*src == (*src)->next)
			tmp = NULL;
		else
			tmp = (*src)->next;
		ft_lstadd_front(dest, *src);
		*src = tmp;
	}
}
