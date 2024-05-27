/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:12:00 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/20 15:24:31 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calc_moves(t_list **set, t_list **targets)
{
	t_list	*aux;
	t_list	*target;
	int		len;
	int		moves;

	aux = *set;
	len = ft_lstlen(set);
	while (len--)
	{
		target = get_target(aux->content, targets);
		moves = aux->cost + target->cost;
		if (aux->above == target->above)
		{
			if (aux->cost > target->cost)
				moves -= target->cost;
			else
				moves -= aux->cost;
		}
		aux->moves = moves;
		aux = aux->next;
	}
}

static t_list	*get_less_moves(t_list **stk)
{
	t_list	*aux;
	t_list	*res;
	int		less;
	int		len;

	aux = *stk;
	less = 2147483647;
	len = ft_lstlen(stk);
	while (len--)
	{
		if (aux->moves < less)
		{
			less = aux->moves;
			res = aux;
		}
		aux = aux->next;
	}
	return (res);
}

static void	share_moves(t_list **lst_from, t_list **lst_target,
			t_list *from, t_list *target)
{
	if (from->above == 1)
	{
		while (from->cost > 0 && target->cost > 0)
		{
			rotate_both(lst_from, lst_target);
			(from->cost)--;
			(target->cost)--;
		}
	}
	else
	{
		while (from->cost > 0 && target->cost > 0)
		{
			reverse_both(lst_from, lst_target);
			(from->cost)--;
			(target->cost)--;
		}
	}
}

static void	do_moves(t_list **lst_from, t_list **lst_target)
{
	t_list	*from;
	t_list	*target;

	from = get_less_moves(lst_from);
	target = get_target(from->content, lst_target);
	if (from->above == target->above)
		share_moves(lst_from, lst_target, from, target);
	while ((from->cost)-- > 0)
	{
		if (from->above == 1)
			rotate_a(lst_from, lst_target);
		else
			reverse_a(lst_from, lst_target);
	}
	while ((target->cost)-- > 0)
	{
		if (target->above == 1)
			rotate_b(lst_from, lst_target);
		else
			reverse_b(lst_from, lst_target);
	}
}

void	do_sort(t_list **stk_a, t_list **stk_b)
{
	while (ft_lstlen(stk_a) > 3)
	{
		set_stacks(stk_a, stk_b);
		calc_moves(stk_a, stk_b);
		do_moves(stk_a, stk_b);
		push_b(stk_b, stk_a);
	}
	if (ft_lstlen(stk_a) == 2)
		order_2(stk_a, stk_b);
	else
		order_3(stk_a, stk_b);
	if (*stk_b)
	{
		max_top(stk_a, stk_b);
		move_back(stk_a, stk_b);
	}
}
