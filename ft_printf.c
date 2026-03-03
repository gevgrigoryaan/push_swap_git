/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:38:14 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/03 17:40:02 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_conversion(const char type, va_list *args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	else if ((type == 'i') || (type == 'd'))
		return (ft_putnbr(va_arg(*args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hexa(va_arg(*args, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		check;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			check = ft_conversion(*(++format), &args);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(2, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
