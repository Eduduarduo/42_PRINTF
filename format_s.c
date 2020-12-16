/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/03 17:01:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(t_flags *flags, va_list args)
{	
	int		count;
	int		len;
	int		precision;
	char	*str;

	count = 0;
	ft_printf_star(flags, args);
	str = va_arg(args, char *);
	//if(str == NULL)
	//	str = "(null)";
	len = ft_strlen(str);
	precision = flags->prec > len ? len : flags->prec;
	if(flags->len ==0 || (flags->prec == -1 && len >= flags->width))
		while (*str)
			count += ft_putchar_ret(*str++);
	//else TRABALHAR QND aplicado AS FLAGS PRECision and width
	return (count);
}
