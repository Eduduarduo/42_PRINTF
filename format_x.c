/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/17 00:32:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitcounter(unsigned long int n)
{
	if (!(n / 16))
		return (1);
	else
		return (digitcounter(n / 16) + 1);
}

char		*ft_itoa_base(unsigned long int n, char type)
{
	char	*hexnumber;
	int		len;
	char	*base;

	base = type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	len = digitcounter(n);
	if (!(hexnumber = malloc((len + 1) * sizeof(*hexnumber))))
		return (NULL);
	hexnumber[len] = '\0';
	while (len--)
	{
		hexnumber[len] = base[n % 16];
		n /= 16;
	}
	return (hexnumber);
}

static int	ft_printf_xa(t_flags *flags, int len, char *number)
{
	int count;

	count = 0;
	if (flags->minus == 0 && flags->zero == 1 && flags->prec == -1)
		count += ft_putflags(flags->width - len, '0');
	else if (flags->minus == 0 && flags->zero == 1)
		count += ft_putflags(flags->width - len, ' ');
	else if (flags->minus == 0 && flags->zero == 0)
		count += ft_putflags(flags->width - len, ' ');
	count += ft_printf(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - len, ' ');
	return (count);
}

static int	ft_printf_xb(t_flags *flags, int len, char *number)
{
	int count;

	count = 0;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->prec, ' ');
	count += ft_putflags(flags->prec - len, '0');
	count += ft_printf(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->prec, ' ');
	return (count);
}

int			ft_printf_x(t_flags *flags, va_list args)
{
	int		count;
	int		dec;
	int		len;
	char	*number;

	ft_printf_star(flags, args);
	dec = va_arg(args, int);
	number = ft_itoa_base((unsigned int)dec, flags->conversion);
	count = 0;
	len = ft_strlen(number);
	if (flags->prec == 0 && dec == 0)
		count += ft_putflags(flags->width, ' ');
	else if (flags->len == 0 || (len >= flags->width && len >= flags->prec))
		count += ft_printf(number);
	else if (flags->prec > len && flags->prec >= flags->width)
		count += ft_putflags(flags->prec - len, '0') + ft_printf(number);
	else if (flags->width >= len && len > flags->prec)
		count += ft_printf_xa(flags, len, number);
	else if (flags->width > flags->prec && flags->prec >= len)
		count += ft_printf_xb(flags, len, number);
	free(number);
	return (count);
}