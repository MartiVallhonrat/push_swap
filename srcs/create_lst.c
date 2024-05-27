/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:11:54 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/11 17:56:53 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_lst(int *arr, int len)
{
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	while (len)
	{
		new = ft_lstnew(arr[len - 1]);
		if (!new)
		{
			ft_lstclear(&lst);
			return (NULL);
		}
		ft_lstadd_front(&lst, new);
		len--;
	}
	return (lst);
}
