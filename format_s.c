/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/18 19:12:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_sa(t_flags *flags, int len, char *str)
{
	int		count;

	count = 0;
	while ((flags->width-- - len) && !(flags->minus))
		count += flags->zero ? ft_putchar_ret('0') : ft_putchar_ret(' ');
	while (*str)
		count += ft_putchar_ret(*str++);
	while ((flags->width-- - len + 1) && flags->minus)
		count += ft_putchar_ret(' ');
	return (count);
}

static int	ft_printf_sb(t_flags *flags, int prec, char *str)
{
	int		count;

	count = 0;
	while ((flags->width-- - prec) && !(flags->minus))
		count += ft_putchar_ret(' ');
	while (flags->prec-- && *str)
		count += ft_putchar_ret(*str++);
	while ((flags->width-- - prec + 1) && flags->minus)
		count += ft_putchar_ret(' ');
	return (count);
}

static int	ft_printf_sc(t_flags *flags, int len, int prec, char *str)
{
	int		count;

	count = 0;
	if (flags->prec == 0 && flags->width == 0)
		return (0);
	while ((flags->prec-- > len) && (flags->width > len) && !flags->minus)
	{
		count += ft_putchar_ret(' ');
		flags->width--;
	}
	while (!len && (flags->width-- > 0) && !flags->minus)
		count += ft_putchar_ret(' ');
	while (prec-- && *str)
	{
		count += ft_putchar_ret(*str++);
		flags->width--;
	}
	if (flags->minus && !len)
		flags->width++;
	while (flags->minus && flags->width-- > 0)
		count += ft_putchar_ret(' ');
	return (count);
}

int			ft_printf_s(t_flags *flags, va_list args)
{
	int		count;
	int		len;
	int		precision;
	char	*str;

	count = 0;
	ft_printf_star(flags, args);
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	precision = flags->prec > len ? len : flags->prec;
	if (flags->len == 0 || (flags->prec == -1 && len >= flags->width))
		while (*str)
			count += ft_putchar_ret(*str++);
	else if (flags->prec == -1 && flags->width > len)
		count += ft_printf_sa(flags, len, str);
	else if (flags->width > flags->prec)
		count += ft_printf_sb(flags, precision, str);
	else if (flags->width <= flags->prec)
		count += ft_printf_sc(flags, len, precision, str);
	return (count);
}
