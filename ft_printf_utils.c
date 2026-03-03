/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:38:38 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/03 17:27:21 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	return (write(2, &c, 1));
}

int	ft_putnbr(long nb)
{
	long		num;
	int			len;
	int			check;

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
		check = ft_putnbr(nb / 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (write(2, &num, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putnbr_hexa(unsigned long nbr, char up)
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
		check = ft_putnbr_hexa((nbr / 16), up);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (write(2, &base[nbr % 16], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putptr(void *p)
{
	int	len;
	int	check;

	len = 0;
	check = 0;
	if (p == NULL)
		return (write(2, "(nil)", 5), 5);
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	check = ft_putnbr_hexa((unsigned long)p, 'x');
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		if (write (2, "(null)", 6) == -1)
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
