/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:35:46 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/08 15:27:27 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
		p[i++] = (unsigned char)c;
	return (b);
}
/*
#include <string.h>
int main()
{
	char c[12];
	char *b = "12345678901234";
	//char *a = memset(b, 1000, 12);
	char *p = ft_memset(b, 10, 123);
	return 0;
}
*/
