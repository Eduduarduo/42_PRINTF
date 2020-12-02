/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagscenter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/02 18:00:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isconversion(t_flags *flags, va_list args)
{
	int count;
//printf("entro no is Convertion");
	count = 0;

    if (flags->conversion == 'c')
    {   
        //printf("Entrou Letra C");
        count += ft_printf_c(flags, args);
    }


	/*else if (flags->conversion == 'x' || flags->conversion == 'X')
	if (flags->conversion == 'd' || flags->conversion == 'i')
	{	printf("Entrou Letra D");
		count += ft_printf_d(flags, args);
	}
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
		count += ft_printf_pct(flags, args);
	else
		flags->len = 0; */
	return (count);
}

int     ft_printf_c(t_flags *flags, va_list args)
{
    int     count;
    char    c;

    count = 0;
    
    c = va_arg(args, int);
    //printf("O --%c--", c);
    count += ft_putchar_ret(c);

    return (count);
}
