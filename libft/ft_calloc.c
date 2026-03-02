/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:33:49 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/09 14:32:16 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	if (count && size > ~(size_t)0 / count)
		return (NULL);
	p = (unsigned char *)malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
/*
#include <limits.h>
#include <stdio.h>
int main()
{
	void *p = ft_calloc(INT_MIN, INT_MIN);
	printf("%p", p);
	free(p);
	return 0;
}
*/
