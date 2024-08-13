/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:07:58 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/27 15:57:42 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(char specifier, va_list *ap)
{
	int	i;

	i = 0;
	if (specifier == 'c')
		i += ft_print_char(va_arg(*ap, int));
	else if (specifier == 's')
		i += ft_print_str(va_arg(*ap, char *));
	else if (specifier == 'p')
		i += ft_print_pointer(va_arg(*ap, void *), "0123456789abcdef");
	else if (specifier == 'd')
		i += ft_putnbr(va_arg(*ap, int));
	else if (specifier == 'i')
		i += ft_putnbr(va_arg(*ap, int));
	else if (specifier == 'u')
		i += ft_putnbr(va_arg(*ap, unsigned int));
	else if (specifier == 'x')
		i += ft_print_hex(va_arg(*ap, unsigned int), 16, "0123456789abcdef");
	else if (specifier == 'X')
		i += ft_print_hex(va_arg(*ap, unsigned int), 16, "0123456789ABCDEF");
	else
		i += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			i += ft_printf_format(*(++str), &ap);
		else
			i += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (i);
}
