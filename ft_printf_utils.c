/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/12/21 14:13:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_ret(char c)
{
	write(1, &c, 1);
	return (1);
}

int				ft_putnbr_ret(int n)
{
	unsigned	i;
	int			count;

	count = 1;
	if (n < 0)
	{
		ft_putchar_ret('-');
		i = n * -1;
		count++;
	}
	else
		i = n;
	if (i >= 10)
		count += ft_putnbr_ret(i / 10);
	ft_putchar_ret(i % 10 + 48);
	return (count);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
return (0);
}

int		ft_strlen(char	*str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_numlen(int num)
{
	int i;

	i = 1;
	if (num < 0)
		i++;
	while (num >= 10 || num <= -10)
	{
		num /= 10;
		i++;
	}
	return (i);
}
