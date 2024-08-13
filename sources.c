/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:13:50 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/27 15:54:09 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_print_char('-');
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr (n / 10);
		i += ft_putnbr (n % 10);
	}
	else
		i += ft_print_char (n + '0');
	return (i);
}

int	ft_print_hex(unsigned int n, unsigned long base, char *symbols)
{
	int		i;

	if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		i = ft_print_hex(n / base, base, symbols);
		return (i + ft_print_hex(n % base, base, symbols));
	}
	return (i);
}
