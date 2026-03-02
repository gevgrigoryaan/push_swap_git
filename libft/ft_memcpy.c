/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:45:56 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/09 14:35:35 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*s;

	if (!dst && !src)
		return (dst);
	dest = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n > 0)
	{
		*(dest++) = *(s++);
		n--;
	}
	return (dst);
}
