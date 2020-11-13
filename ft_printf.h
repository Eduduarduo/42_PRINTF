/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/11/09 12:32:26 by root             ###   ########.fr       */
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

void init_flags(t_flags *flags);

int	ft_isdigit(int c);


#endif
