/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sourcesp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:29 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/27 16:03:25 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr, char *symbols)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	i += write(1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	i += ft_print_hexp((unsigned long long)ptr, 16, symbols);
	return (i);
}

int	ft_print_hexp(unsigned long long n, unsigned long long base, char *symbols)
{
	int		i;

	if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		i = ft_print_hexp(n / base, base, symbols);
		return (i + ft_print_hexp(n % base, base, symbols));
	}
	return (i);
}
