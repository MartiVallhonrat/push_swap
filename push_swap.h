/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:59:51 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/14 17:11:54 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				cost;
	int				above;
	int				moves;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*get_args(int argc, char *argv[]);
int		check_nan(int argc, char *arg[]);
int		check_repeat(int *nums, int len);
char	**ft_split_2c(char const *s, char c, char c2, int *len);
long	ft_atoi_lo(char *str);
t_list	*free_cnums(char ***c_nums);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstlen(t_list **lst);
void	ft_lstclear(t_list **lst);
t_list	*create_lst(int *arr, int len);
void	swap(t_list **stk);
void	swap_a(t_list **stk_a, t_list **stk_b);
void	swap_b(t_list **stk_a, t_list **stk_b);
void	swap_both(t_list **stk_a, t_list **stk_b);
void	push(t_list **dest, t_list **src);
void	push_a(t_list **dest, t_list **src);
void	push_b(t_list **dest, t_list **src);
void	rotate(t_list **stk_a);
void	rotate_a(t_list **stk_a, t_list **stk_b);
void	rotate_b(t_list **stk_a, t_list **stk_b);
void	rotate_both(t_list **stk_a, t_list **stk_b);
void	reverse(t_list **stk);
void	reverse_a(t_list **stk_a, t_list **stk_b);
void	reverse_b(t_list **stk_a, t_list **stk_b);
void	reverse_both(t_list **stk_a, t_list **stk_b);
void	ft_sort(t_list **stk_a, t_list **stk_b);
void	do_sort(t_list **stk_a, t_list **stk_b);
void	set_stacks(t_list **stk_a, t_list **stk_b);
t_list	*get_max(t_list **stk);
t_list	*get_min(t_list **stk);
t_list	*get_target(int content, t_list **stk);
int		is_sorted(t_list **stk);
int		is_rev_sorted(t_list **stk);
void	order_3(t_list **stk_a, t_list **stk_b);
void	order_2(t_list **stk_a, t_list **stk_b);
void	max_top(t_list **stk_a, t_list **stk_b);
void	move_back(t_list **stk_a, t_list **stk_b);

#endif
