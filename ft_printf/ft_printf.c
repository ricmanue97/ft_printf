/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:49:23 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/09 12:14:33 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (*format == '%')
			i += ft_printf_format(*(++format, ap));
		else
			i += write(1, format, 1);
		i++;
	}
	va_end(ap);
	return (i);
}
int	ft_printf_format(char specifier, va_list ap)
{
	int i;

	i = 0;
	if (specifier == 'c')
		i += ft_printf_char(va_arg(ap, int));
	if (specifier == 's')
		i += ft_printf_string(va_arg(ap, char *));
	if (specifier == 'p')
		i += ft_printf_pointer(va_arg(ap, void *));
	if (specifier == 'd')
		i += ft_printf_digit(va_arg(ap, int));
	if (specifier == 'i')
		i += ft_printf_intbase(va_arg(ap, int));
	if (specifier == 'u')
		i += ft_printf_undigit(va_arg(ap, unsigned int));
	if (specifier == 'x')
		i += ft_printf_hex(va_arg(ap, long int));
	if (specifier == 'X')
		i += ft_printf_Hex(va_arg(ap, long int));
	if (specifier == '%')
		i += ft_printf_char(va_arg(ap, int));

}
