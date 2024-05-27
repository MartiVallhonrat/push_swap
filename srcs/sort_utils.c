/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:11:37 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/13 19:48:16 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_max(t_list **stk)
{
	int		len;
	int		max;
	t_list	*res;
	t_list	*bubble;

	len = ft_lstlen(stk);
	max = -2147483648;
	res = NULL;
	bubble = *stk;
	while (len--)
	{
		if (bubble->content > max)
		{
			max = bubble->content;
			res = bubble;
		}
		bubble = bubble->next;
	}
	return (res);
}

t_list	*get_min(t_list **stk)
{
	int		len;
	int		min;
	t_list	*res;
	t_list	*bubble;

	len = ft_lstlen(stk);
	min = 2147483647;
	res = NULL;
	bubble = *stk;
	while (len--)
	{
		if (bubble->content < min)
		{
			min = bubble->content;
			res = bubble;
		}
		bubble = bubble->next;
	}
	return (res);
}

static void	set_stack(t_list **stk, int len)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = *stk;
	while (i < (len / 2 + (len % 2)))
	{
		aux->above = 1;
		aux->cost = i++;
		aux = aux->next;
	}
	i = 1;
	aux = (*stk)->prev;
	while ((i - 1) < (len / 2))
	{
		aux->above = 0;
		aux->cost = i++;
		aux = aux->prev;
	}
}

void	set_stacks(t_list **stk_a, t_list **stk_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(stk_a);
	set_stack(stk_a, len_a);
	if (*stk_b)
	{
		len_b = ft_lstlen(stk_b);
		set_stack(stk_b, len_b);
	}
}

void	order_3(t_list **stk_a, t_list **stk_b)
{
	if (is_sorted(stk_a))
		return ;
	if ((*stk_a)->content < (*stk_a)->next->content
		&& (*stk_a)->next->content > (*stk_a)->prev->content)
	{
		reverse_a(stk_a, stk_b);
		if ((*stk_a)->content > (*stk_a)->next->content)
			swap_a(stk_a, stk_b);
	}
	if ((*stk_a)->content > (*stk_a)->next->content
		&& (*stk_a)->next->content < (*stk_a)->prev->content
		&& (*stk_a)->content > (*stk_a)->prev->content)
		rotate_a(stk_a, stk_b);
	if ((*stk_a)->content > (*stk_a)->next->content
		&& (*stk_a)->next->content < (*stk_a)->prev->content
		&& (*stk_a)->content < (*stk_a)->prev->content)
		swap_a(stk_a, stk_b);
	if ((*stk_a)->content > (*stk_a)->next->content
		&& (*stk_a)->next->content > (*stk_a)->prev->content)
	{
		rotate_a(stk_a, stk_b);
		swap_a(stk_a, stk_b);
	}
}
