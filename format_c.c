/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/18 18:58:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_c(t_flags *flags, va_list args)
{
	int		count;
	char	c;

	count = 0;
	ft_printf_star(flags, args);
	c = va_arg(args, int);
	if (flags->minus == 1)
	{
		count += ft_putchar_ret(c);
		while (flags->width-- > 1)
			count += ft_putchar_ret(' ');
	}
	else
	{
		while (flags->width-- > 1)
			count += ft_putchar_ret(' ');
		count += ft_putchar_ret(c);
	}
	return (count);
}
