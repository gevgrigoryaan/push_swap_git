/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:29:13 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 20:35:38 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strleng(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchrg(char *s, int c)
{
	while (s && *s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strdupg(char *s1)
{
	size_t	i;
	char	*s;

	if (!s1)
		return (NULL);
	s = (char *)malloc(ft_strleng(s1) + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoing(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s;

	s = (char *)malloc(ft_strleng(s1) + ft_strleng(s2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		s[j++] = s2[i++];
	s[j] = '\0';
	return (s);
}
