/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:04:22 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/19 16:11:17 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int	ft_printf(const	char *s, ...);
int	check_placeholder(char c, int *count, va_list args);
int	ft_putchar_count(char c);
int	ft_putstr_count(char *s);
int	ft_strlen(const char *s);
int	ft_putnbr_count(int n);
int	ft_putnbr_count_uns(unsigned int n);
int	ft_putnbr_base_count_uns(unsigned int nbr, char *base);
int	ft_putnbr_base_count_ulong(void *nbr, char *base);

#endif
