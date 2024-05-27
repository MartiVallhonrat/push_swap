/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:11 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/30 18:48:51 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_n(t_list **strs, int fd)
{
	char	*buff_str;
	int		sz;

	while (find_n(strs[fd], 1) == 0)
	{
		buff_str = malloc(BUFFER_SIZE + 1);
		if (!buff_str)
			return (0);
		sz = read(fd, buff_str, BUFFER_SIZE);
		if (sz == -1)
			return (free(buff_str), 0);
		if (sz == 0)
			return (free(buff_str), 1);
		buff_str[sz] = '\0';
		if (ft_lstadd(&strs[fd], &buff_str) == 0)
			return (0);
	}
	return (1);
}

int	get_fd_line(char **line, t_list *str)
{
	char	*str_n;
	int		i;
	int		line_len;

	while (str->next != NULL)
	{
		*line = ft_strjoin(*line, str->content);
		if (!(*line))
			return (0);
		str = str->next;
	}
	line_len = find_n(str, 2);
	str_n = malloc (line_len + 1);
	if (!str_n)
		return (0);
	i = -1;
	while (++i < line_len)
		str_n[i] = str->content[i];
	str_n[i] = '\0';
	*line = ft_strjoin(*line, str_n);
	free(str_n);
	if (!(*line))
		return (0);
	return (1);
}

int	alloc_rem(t_list *str, t_list **strs, int fd)
{
	char	*content;
	char	*new_content;
	int		i;

	content = str->content;
	while (*content != '\n')
		content++;
	new_content = malloc (ft_strlen(++content) + 1);
	if (!new_content)
		return (0);
	i = 0;
	while (content[i])
	{
		new_content[i] = content[i];
		i++;
	}
	new_content[i] = '\0';
	if (ft_lstadd(&strs[fd], &new_content) == 0)
		return (0);
	return (1);
}

int	clean_lst(t_list **strs, int fd)
{
	t_list	*temp;
	t_list	*str;
	int		str_len;

	str = strs[fd];
	while (str->next != NULL)
	{
		temp = str->next;
		free(str->content);
		free(str);
		str = temp;
	}
	strs[fd] = NULL;
	str_len = find_n(str, 1);
	if (!(str_len == 0 || str_len == BUFFER_SIZE
			|| ft_strlen(str->content + str_len) == 0))
		if (alloc_rem(str, strs, fd) == 0)
			return (free(str->content), free(str), 0);
	free(str->content);
	free(str);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*strs[OPEN_MAX + 1];
	int				line_len;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	if (get_n(strs, fd) == 0)
	{
		free_all(&strs[fd]);
		return (NULL);
	}
	line_len = find_n(strs[fd], 2);
	if (!line_len)
		return (0);
	line = NULL;
	if (get_fd_line(&line, strs[fd]) == 0)
	{
		free_all(&strs[fd]);
		if (line)
			free(line);
		return (NULL);
	}
	if (clean_lst(strs, fd) == 0)
		return (NULL);
	return (line);
}
