/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/11/09 12:33:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	int count;
	va_list	args;
	int		i;
	char	c;
	t_flags flags;

	count = 0;
	i = 0;

	va_start(args, str);
	while (str[i])
	{
	if (str[i] == '%')
		{
			i++;
			init_flags(&flags);
			
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

int		readflag(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '*' || str[i] == '.' || ft_isdigit(str[i]))
	{
		//
		if (ft_isdigit(str[i]))
			while (ft_isdigit(str[i]))
			{
				if(flags->prec == -1)
					flags->width = (flags->width * 10) + (str[i] - '0');
				if(flags->prec == 0)
					flags->width = (flags->width * 10) + (str[i] - '0');
				i++;
			}
		else
			i++;	
	}
	flags->conversion = str[i];
	flags->len = i;
	return (i);
}