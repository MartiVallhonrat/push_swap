/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:36:39 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/30 19:35:51 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_n(t_list *node, int call)
{
	char	*content;
	int		counter;

	counter = 0;
	if (node == NULL)
		return (0);
	while (node)
	{
		content = node->content;
		while (*content != '\0' && *content != '\n')
		{
			content++;
			counter++;
		}
		if (*content == '\n')
			return (++counter);
		node = node->next;
	}
	if (call == 2)
		return (counter);
	return (0);
}

int	ft_lstadd(t_list **str, char **buf_str)
{
	t_list	*new;
	t_list	*temp;

	new = (t_list *) malloc(sizeof (t_list));
	if (!new)
	{
		free(*buf_str);
		return (0);
	}
	new->content = *buf_str;
	new->next = NULL;
	if (*str == NULL)
		*str = new;
	else
	{
		temp = *str;
		while ((*str)->next != NULL)
			*str = (*str)->next;
		(*str)->next = new;
		*str = temp;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	char	*str;

	len1 = ft_strlen(s1);
	str = (char *) malloc (len1 + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1 != NULL && s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[len1++] = s2[i];
	if (s1)
		free(s1);
	str[len1] = '\0';
	return (str);
}

void	free_all(t_list **str)
{
	t_list	*temp;
	t_list	*head;

	head = *str;
	while (head)
	{
		temp = head->next;
		free(head->content);
		free(head);
		head = temp;
	}
	*str = NULL;
}
