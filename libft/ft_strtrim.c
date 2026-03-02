/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:32:27 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/05 22:32:11 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*new_str(char const *s1, size_t i, size_t len)
{
	char		*str;
	size_t		k;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	k = 0;
	while (k < len)
	{
		str[k] = s1[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_isset(s1[i], set) && s1[i])
		i++;
	while (ft_isset(s1[j - 1], set) && j > i)
		j--;
	return (new_str(s1, i, j - i));
}
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strtrim("xxxxasasasxxx", "xx"));
	return 0;
}
*/
