/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 22:31:42 by gegrigor          #+#    #+#             */
/*   Updated: 2026/01/31 22:04:55 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*p;
	size_t		l;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = ft_numlen(n);
	p = (char *)malloc(l + 1);
	if (!p)
		return (NULL);
	p[l--] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		p[l--] = (n % 10) + '0';
		n = n / 10;
	}
	p[l] = n + '0';
	return (p);
}
/*
int	main()
{
	char *a = ft_itoa(-123454321);
	printf("%s", a);
	return 0;
}*/
