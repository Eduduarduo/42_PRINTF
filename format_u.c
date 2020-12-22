/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/21 23:37:07 by edbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen_unsigned(unsigned int num)
{
	int i;

	i = 1;
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	int		count;

	count = 1;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	ft_putchar_ret(n % 10 + 48);
	return (count);
}

static int	ft_printf_ua(t_flags *flags, int len, int number)
{
	int		count;

	count = 0;
	if (flags->minus == 0)
	{
		if (flags->zero && flags->prec == -1)
			count += ft_putflags(flags->width - len, '0');
		else
			count += ft_putflags(flags->width - len, ' ');
		count += ft_putnbr_unsigned(number);
	}
	else
		count += ft_putnbr_unsigned(number)
		+ ft_putflags(flags->width - len, ' ');
	return (count);
}

static int	ft_printf_ub(t_flags *flags, int len, int number)
{
	int		count;

	count = 0;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->prec, ' ');
	count += ft_putflags(flags->prec - len, '0');
	count += ft_putnbr_unsigned(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->prec, ' ');
	return (count);
}

int			ft_printf_u(t_flags *flags, va_list args)
{
	int				count;
	int				len;
	unsigned int	number;

	ft_printf_star(flags, args);
	number = va_arg(args, unsigned int);
	count = 0;
	len = ft_numlen_unsigned(number);
	if (flags->prec == 0 && number == 0)
		count += ft_putflags(flags->width, ' ');
	else if (flags->len == 0 || (len >= flags->width && len >= flags->prec))
		count += ft_putnbr_unsigned(number);
	else if (flags->prec > len && flags->prec >= flags->width)
		count += ft_putflags(flags->prec - len, '0')
					+ ft_putnbr_unsigned(number);
	else if (flags->width >= len && len > flags->prec)
		count += ft_printf_ua(flags, len, number);
	else if (flags->width > flags->prec && flags->prec >= len)
		count += ft_printf_ub(flags, len, number);
	return (count);
}
