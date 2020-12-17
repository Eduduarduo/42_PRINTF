/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/17 13:27:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_percent(t_flags *flags, va_list args)
{
	int		count;

	ft_printf_star(flags, args);
	count = 0;
	if (flags->minus)
		count += ft_putchar_ret('%');
	while (flags->width-- > 1)
		count += flags->zero ? ft_putchar_ret('0') : ft_putchar_ret(' ');
	if (!flags->minus)
		count += ft_putchar_ret('%');
	return (count);
}