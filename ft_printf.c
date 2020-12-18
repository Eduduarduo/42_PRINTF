/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/18 19:23:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	t_flags	flags;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			init_flags(&flags);
			str++;
			readflag(&flags, str);
			count += ft_isconversion(&flags, args);
			str += flags.len;
		}
		else
			count += ft_putchar_ret(*str);
		str++;
	}
	va_end(args);
	return (count);
}

void	init_flags(t_flags *flags)
{
	flags->len = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->star = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->conversion = '\0';
}

int		readflag(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '*' || str[i] == '.' || ft_isdigit(str[i]))
	{
		readingflag(flags, str[i]);
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
			{
				if (flags->prec == -1)
					flags->width = (flags->width * 10) + (str[i] - '0');
				if (flags->prec == 0)
					flags->width = (flags->width * 10) + (str[i] - '0');
				i++;
			}
		}
		else
			i++;
	}
	flags->conversion = str[i];
	flags->len = i;
	return (i);
}

void	readingflag(t_flags *flags, const char str)
{
	if(str == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	if ((str == '0') && flags->minus != 1 && flags->width == 0)
		flags->zero = 1;
	if (str == '.')
		flags->prec = (flags->prec == -1) ? 0 : -2;
	if (str == '*')
	{
		if (flags->prec == -1)
			flags->star = 1;
		else
			flags->star = (flags->star == 0) ? 2 : 3;
	}
}
