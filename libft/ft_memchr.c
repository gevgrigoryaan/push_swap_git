/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:21:12 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/09 14:34:30 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	unsigned char		cc;

	ss = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (n > 0)
	{
		if (*ss == cc)
			return ((void *)ss);
		ss++;
		n--;
	}
	return (NULL);
}
