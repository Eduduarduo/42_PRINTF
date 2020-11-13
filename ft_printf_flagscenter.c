/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagscenter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/11/09 12:42:15 by root             ###   ########.fr       */
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
		count += ft_printf_pct(flags, args);
	else
		flags->len = 0;
	return (count);
}