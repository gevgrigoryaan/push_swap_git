/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:21:38 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/14 18:32:59 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;
	char			*ss;

	cc = (unsigned char)c;
	ss = (char *)s;
	while (*ss)
	{
		if (*ss == cc)
			return (ss);
		ss++;
	}
	if (*ss == cc)
		return (ss);
	return (NULL);
}
/*
int	main()
{
	char *a = ft_strchr("abcde", 'b');
	printf("%s", a);
	return 0;
}*/
