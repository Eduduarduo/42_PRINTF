/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/17 13:28:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_pa(t_flags *flags)
{
	int	count;

	count = 0;
	while (flags->width-- - 2 > 0)
		count += ft_putchar_ret(' ');
	count += ft_printf("0x");
	return (count);
}

static int	ft_printf_pb(t_flags *flags, int len, char *end_hex)
{
	int	count;

	count = ft_printf("0x");
	while (flags->prec-- - len)
		count += ft_putchar_ret('0');
	count += ft_printf(end_hex);
	return (count);
}

static int	ft_printf_pc(t_flags *flags, int len, char *end_hex)
{
	int	count;

	count = 0;
	len = len + 2;
	if (flags->minus == 0)
	{
		while (flags->width-- - len > 0)
			count += (flags->zero && flags->prec == -1)
				? ft_putchar_ret('0') : ft_putchar_ret(' ');
		count += ft_printf("0x%s", end_hex);
	}
	else
	{
		count += ft_printf("0x%s", end_hex);
		while (flags->width-- - len > 0)
			count += ft_putchar_ret(' ');
	}
	return (count);
}

static int	ft_printf_pd(t_flags *flags, int len, char *end_hex)
{
	int	count;
	int	point;

	count = 0;
	point = flags->prec;
	if (flags->minus == 0)
		while (flags->width-- - point)
			count += ft_putchar_ret(' ');
	count += ft_printf("0x");
	while (flags->prec-- - len)
		count += ft_putchar_ret('0');
	count += ft_printf(end_hex);
	if (flags->minus == 1)
		while (flags->width-- - point)
			count += ft_putchar_ret(' ');
	return (count);
}

int			ft_printf_p(t_flags *flags, va_list args)
{
	int						count;
	int						len;
	char					*end_hex;
	unsigned long int		end_dec;

	ft_printf_star(flags, args);
	end_dec = va_arg(args, unsigned long int);
	end_hex = ft_itoa_base(end_dec, 'x');
	count = 0;
	len = ft_strlen(end_hex);
	if (flags->prec == 0 && end_dec == 0)
		count += ft_printf_pa(flags);
	else if (flags->len == 0 || (len >= flags->width && len >= flags->prec))
		count += ft_printf("0x%s", end_hex);
	else if (flags->prec > len && flags->prec >= flags->width)
		count += ft_printf_pb(flags, len, end_hex);
	else if (flags->width >= len && len > flags->prec)
		count += ft_printf_pc(flags, len, end_hex);
	else if (flags->width > flags->prec && flags->prec >= len)
		count += ft_printf_pd(flags, len, end_hex);
	free(end_hex);
	return (count);
}