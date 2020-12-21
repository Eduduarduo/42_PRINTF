/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagscenter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/18 19:31:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isconversion(t_flags *flags, va_list args)
{
	int count;

	count = 0;
	if (flags->conversion == 'd' || flags->conversion == 'i')
		count += ft_printf_d(flags, args);
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		count += ft_printf_x(flags, args);
	else if (flags->conversion == 'c')
		count += ft_printf_c(flags, args);
	else if (flags->conversion == 's')
		count += ft_printf_s(flags, args);
	else if (flags->conversion == 'p')
		count += ft_printf_p(flags, args);
	else if (flags->conversion == 'u')
		count += ft_printf_u(flags, args);
	else if (flags->conversion == '%')
		count += ft_printf_percent(flags, args);
	else
		flags->len = 0;
	return (count);
}

void	ft_printf_star(t_flags *flags, va_list args)
{
	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->prec = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->prec = va_arg(args, int);
	}
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
		flags->zero = 0;
	}
	if (flags->prec < 0)
		flags->prec = -1;
}

int		ft_putflags(int condition, char c)
{
	int count;

	count = 0;
	while (condition-- > 0)
		count += ft_putchar_ret(c);
	return (count);
}
