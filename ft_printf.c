/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/10/30 17:57:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	int count;
	va_list	args;
	int		i;
	char	c;

	count = 0;
	i = 0;

	va_start(args, str);
	while (str[i])
	{
	if (str[i] == '%')
		{
			i++;
			if ( str[i] == 'c')
			{
				c = va_arg(args, int);
				count += ft_putchar_ret(c);
			}
		}
		else
			count += ft_putchar_ret(str[i]);
		i++;
	}

	va_end(args);
	return (count);
}

int		ft_putchar_ret(char c)
{
	write(1, &c, 1);
	return (1);
}

void init_flags(t_flags *flags)
{
	flags->len = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->star = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->conversion =  '\0';
}
