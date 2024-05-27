/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_custom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:21:45 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/07 16:19:13 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	count_words(const char *str, char c, char c2)
{
	size_t	i;
	int		trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && *str != c2 && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c || *str == c2)
			trigger = 0;
		str++;
	}
	return (i);
}

size_t	next_word(char const *str, size_t *i, char c, char c2)
{
	size_t	size;

	while (str[*i] && (str[*i] == c || str[*i] == c2))
		*i += 1;
	size = 0;
	while (str[*i + size] && str[*i + size] != c
		&& str[*i + size] != c2)
		size++;
	return (size);
}

static char	**free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split_2c(char const *s, char c, char c2, int *len)
{
	char	**strs;
	size_t	words;
	size_t	words_count;
	size_t	word_size;
	size_t	i;

	words = count_words(s, c, c2);
	*len += words;
	strs = ft_calloc(sizeof (char *), words + 1);
	if (!strs)
		return (NULL);
	i = 0;
	words_count = 0;
	while (words_count < words)
	{
		word_size = next_word(s, &i, c, c2);
		strs[words_count] = ft_calloc(sizeof (char), word_size + 1);
		if (!strs[words_count])
			return (free_all(strs));
		ft_strlcpy(strs[words_count++], &s[i], word_size + 1);
		i += word_size;
	}
	return (strs);
}
