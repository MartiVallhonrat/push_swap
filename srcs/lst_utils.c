/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:55:09 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/14 18:49:39 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*dest;

	dest = (t_list *) malloc(sizeof (t_list));
	if (!dest)
		return (NULL);
	dest->content = content;
	dest->cost = 0;
	dest->above = 0;
	dest->moves = 0;
	dest->next = dest;
	dest->prev = dest;
	return (dest);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (*lst)
		{
			new->next = *lst;
			new->prev = (*lst)->prev;
			(*lst)->prev->next = new;
			(*lst)->prev = new;
			*lst = new;
		}
		else
		{
			new->next = new;
			new->prev = new;
			*lst = new;
		}
	}
}

int	ft_lstlen(t_list **lst)
{
	int	len;
	int	first;

	len = 0;
	if (*lst)
	{
		first = (*lst)->content;
		*lst = (*lst)->next;
		len++;
		while ((*lst)->content != first)
		{
			*lst = (*lst)->next;
			len++;
		}
	}
	return (len);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	int		len;

	if (!lst || !*lst)
		return ;
	len = ft_lstlen(lst);
	while (len > 0)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
		len--;
	}
}
