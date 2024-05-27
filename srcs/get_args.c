/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:53:58 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/14 19:23:37 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_nums(char ***strs, int *nums)
{
	long	tmp;
	int		i;
	int		j;
	int		pos;

	i = 0;
	pos = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			tmp = ft_atoi_lo(strs[i][j]);
			if (tmp < INT_MIN || tmp > INT_MAX)
				return (0);
			nums[pos++] = (int)tmp;
			j++;
		}
		i++;
	}
	if (!check_repeat(nums, pos))
		return (0);
	free_cnums(strs);
	return (1);
}

t_list	*free_cnums(char ***c_nums)
{
	int	i;
	int	j;

	i = 0;
	while (c_nums[i])
	{
		j = 0;
		while (c_nums[i][j])
		{
			free(c_nums[i][j]);
			j++;
		}
		free(c_nums[i]);
		i++;
	}
	free(c_nums);
	return (0);
}

char	***get_strs(int argc, char *argv[], int *len)
{
	char	***c_nums;
	int		i;

	c_nums = ft_calloc(sizeof (char **), argc);
	if (!c_nums)
		return (NULL);
	*len = 0;
	i = -1;
	while (++i < (argc - 1))
	{
		c_nums[i] = ft_split_2c(argv[i + 1], ' ', '\t', len);
		if (!c_nums[i])
		{
			free_cnums(c_nums);
			return (NULL);
		}
	}
	return (c_nums);
}

//calloc de argc pq argc-1+1
t_list	*get_args(int argc, char *argv[])
{
	t_list	*lst;
	int		*arr;
	char	***c_nums;
	int		len;

	if (!check_nan(argc, argv))
		return (0);
	c_nums = get_strs(argc, argv, &len);
	if (!c_nums)
		return (NULL);
	arr = malloc(sizeof (int) * len);
	if (!arr)
		return (free_cnums(c_nums));
	if (!get_nums(c_nums, arr))
		return (free(arr), free_cnums(c_nums));
	lst = create_lst(arr, len);
	free(arr);
	if (!lst)
		return (NULL);
	return (lst);
}
