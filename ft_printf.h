/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:08:48 by ricmanue          #+#    #+#             */
/*   Updated: 2024/05/27 15:52:00 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_putnbr(long n);
int	ft_print_hex(unsigned int n, unsigned long base, char *symbols);
int	ft_print_pointer(void *ptr, char *symbols);
int	ft_print_hexp(unsigned long long n, unsigned long long base, char *symbols);
int	ft_printf(const char *str, ...);
#endif
