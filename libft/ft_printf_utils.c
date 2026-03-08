/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:38:38 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/08 17:31:43 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_p(char c)
{
	return (write(2, &c, 1));
}

int	ft_putnbr_p(long nb)
{
	long	num;
	int		len;
	int		check;

	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len += 1;
		nb *= -1;
	}
	num = nb % 10 + '0';
	if (nb >= 10)
	{
		check = ft_putnbr_p(nb / 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (write(2, &num, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putnbr_hexa_p(unsigned long nbr, char up)
{
	int		len;
	char	*base;
	int		check;

	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		check = ft_putnbr_hexa_p((nbr / 16), up);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (write(2, &base[nbr % 16], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putptr_p(void *p)
{
	int	len;
	int	check;

	len = 0;
	check = 0;
	if (p == NULL)
		return (write(2, "(nil)", 5), 5);
	if (ft_putstr_p("0x") == -1)
		return (-1);
	len += 2;
	check = ft_putnbr_hexa_p((unsigned long)p, 'x');
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}

int	ft_putstr_p(char *s)
{
	int	len;

	if (!s)
	{
		if (write(2, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*s != '\0')
	{
		if (write(2, s, 1) == -1)
			return (-1);
		len++;
		s++;
	}
	return (len);
}
