/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:03:55 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/01 15:03:08 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		get_n(t_list **strs, int fd);
int		get_fd_line(char **line, t_list *str);
int		alloc_rem(t_list *str, t_list **strs, int fd);
int		clean_lst(t_list **strs, int fd);
int		find_n(t_list *node, int call);
int		ft_lstadd(t_list **str, char **buf_str);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	free_all(t_list **strs);

#endif
