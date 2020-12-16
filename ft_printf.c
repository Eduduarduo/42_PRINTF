/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/03 17:05:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	int count;
	va_list	args;
	//int		i;
	//char	c;
	t_flags flags;

	count = 0;
	//i = 0;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			//i++;
			init_flags(&flags);
			//printf("O que esta dentro flag->convertion .... %c .... \n", flags.conversion );
			str++;
			//printf("STR .... %s .... \n", str);
			readflag(&flags, str);
			//printf("222222222222 flag->convertion .... %c .... 22222\n", flags.conversion );
			/*if ( str[i] == 'c')
			{
				c = va_arg(args, int);
				count += ft_putchar_ret(c);
			}*/

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

void init_flags(t_flags *flags)
{
	flags->len = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->star = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->conversion =  '\0';
	//Outra maneira de inicializar a struct(t_flags) flags {0};
}

int		readflag(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '*' || str[i] == '.' || ft_isdigit(str[i]))
	{
		readingflag(flags, str[i]);
		//
		//printf("ENTROU 1   ");
		if (ft_isdigit(str[i]))
		{	//printf("ENTROU  2  ");
			while (ft_isdigit(str[i]))
			{
				if(flags->prec == -1)
					flags->width = (flags->width * 10) + (str[i] - '0');
				if(flags->prec == 0)
					flags->width = (flags->width * 10) + (str[i] - '0');
				i++;
			}
		}
		else
			i++;	
	}
	flags->conversion = str[i];
	//printf("imprimindi str i === %c ===   ", str[i]);
	flags->len = i;
	return (i);
}

void    readingflag(t_flags *flags, const char str)
{
    if(str == '-')
    {
        flags->minus = 1;
        flags->zero = 0;
    }
    if((str == '0') && flags->minus != 1 && flags->width == 0)
        flags->zero = 1;
    if(str == '.')
        flags->prec = (flags->prec == -1) ? 0 : -2;
    if (str == '*')
    {
        if (flags->prec ==-1)
            flags->star = 1;
        else
            flags->star = (flags->star == 0) ? 2 : 3;
    }
}
