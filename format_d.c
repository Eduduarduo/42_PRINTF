/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/16 22:03:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_da(t_flags *flags, int len, int number)
{
	int count;

	count = 0;
	if (number < 0)
	{
		number = number * (-1);
		flags->prec++;
		count += ft_putchar_ret('-');
	}
	count += ft_putflags(flags->prec - len, '0') + ft_putnbr_ret(number);
	return (count);
}

static int	ft_printf_db(t_flags *flags, int len, int number)
{
	int count;

	count = 0;
	if (number < 0 && flags->prec == -1)
	{
		number = number * (-1);
		flags->prec++;
		if (flags->zero)
			count += ft_putchar_ret('-') + ft_putflags(flags->width - len, '0');
		else
			count += ft_putflags(flags->width - len, ' ') + ft_putchar_ret('-');
		count += ft_putnbr_ret(number);
	}
	else if (number < 0)
	{
		while ((flags->prec >= 0) && (flags->width-- - len))
			count += ft_putchar_ret(' ');
		count += ft_putnbr_ret(number);
	}
	else if (flags->zero && flags->prec == -1)
		count += ft_putflags(flags->width - len, '0') + ft_putnbr_ret(number);
	else
		count += ft_putflags(flags->width - len, ' ') + ft_putnbr_ret(number);
	return (count);
}

static int	ft_printf_dc(t_flags *flags, int len, int number)
{
	int count;

	count = 0;
	if (number < 0)
		flags->prec++;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->prec, ' ');
	if (number < 0)
	{
		count += ft_putchar_ret('-');
		number = number * (-1);
	}
	count += ft_putflags(flags->prec - len, '0') + ft_putnbr_ret(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->prec, ' ');
	return (count);
}

int			ft_printf_d(t_flags *flags, va_list args)
{
	int len;
	int	number;
	int count;

	ft_printf_star(flags, args);
	number = va_arg(args, int);
	len = ft_numlen(number);
	count = 0;
	if (flags->prec == 0 && number == 0)
		count += ft_putflags(flags->width, ' ');
	else if (flags->len == 0 || (len >= flags->width && len > flags->prec))
		count += ft_putnbr_ret(number);
	else if (flags->prec >= len && flags->prec >= flags->width)
		count += ft_printf_da(flags, len, number);
	else if (flags->width >= len && len > flags->prec)
	{
		if (flags->minus == 0)
			count += ft_printf_db(flags, len, number);
		else
			count += ft_putnbr_ret(number) + ft_putflags(flags->width - len, ' ');
	}
	else if (flags->width > flags->prec && flags->prec >= len)
		count += ft_printf_dc(flags, len, number);
	return (count);
}