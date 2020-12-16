/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/15 23:36:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>


typedef struct s_flags {
	int		len;
	int		width;
	int		prec;
	int		star;
	int		minus;
	int 	zero;
	char	conversion;
}				t_flags;

int ft_printf(const char *, ...);

int ft_putchar_ret(char c);

int		ft_putnbr_ret(int n);

int	ft_strlen(char	*str);

int		ft_numlen(int num);

int	ft_isdigit(int c);

void init_flags(t_flags *flags);

void    readingflag(t_flags *flags, const char str);

int     readflag(t_flags *flags, const char *str);

int     ft_isconversion(t_flags *flags, va_list args);

int     ft_printf_c(t_flags *flags, va_list args);

void	ft_printf_star(t_flags *flags, va_list args);

int		ft_printf_s(t_flags *flags, va_list args);

int		ft_printf_x(t_flags *flags, va_list args);

int		ft_printf_d(t_flags *flags, va_list args);

static int	ft_putnbr_unsigned(unsigned int n);

static int	ft_printf_ub(t_flags *flags, int len, int number);

static int	ft_printf_ua(t_flags *flags, int len, int number);

int		ft_putflags(int condition, char c);


#endif
