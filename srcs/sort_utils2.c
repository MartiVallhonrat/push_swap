/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:09:21 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/14 17:12:51 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_target(int content, t_list **stk)
{
	int		trigger;
	int		i;
	t_list	*bubble;

	trigger = 0;
	i = 0;
	bubble = *stk;
	if (content < get_min(stk)->content)
		return (get_max(stk));
	while (!trigger)
	{
		i = 0;
		--content;
		while (i++ < ft_lstlen(stk))
		{
			if (bubble->content == content)
			{
				trigger = 1;
				break ;
			}
			bubble = bubble->next;
		}
	}
	return (bubble);
}

int	is_sorted(t_list **stk)
{
	t_list	*aux;
	int		len;

	aux = *stk;
	len = ft_lstlen(stk);
	while (len-- - 1)
	{
		if (!(aux->content < aux->next->content))
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	is_rev_sorted(t_list **stk)
{
	t_list	*aux;
	int		len;

	aux = *stk;
	len = ft_lstlen(stk);
	while (len-- - 1)
	{
		if (!(aux->content > aux->next->content))
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	order_2(t_list **stk_a, t_list **stk_b)
{
	if (is_sorted(stk_a))
		return ;
	else
		swap_a(stk_a, stk_b);
}
