/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:27:29 by gegrigor          #+#    #+#             */
/*   Updated: 2026/01/31 22:30:48 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sp;
	char	*ss;

	sp = (char *)s;
	ss = NULL;
	while (*sp)
	{
		if (*sp == (char)c)
			ss = sp;
		sp++;
	}
	if ((char)c == '\0')
		return (sp++);
	return (ss);
}
/*
it	main()
{
	char *a = ft_strrchr("123456789", 'a');
	printf("%s", a);
	printf("%s", strrchr("123456789", 'a'));
	return 0;
}*/
