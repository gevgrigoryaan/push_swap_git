/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_split.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: gegrigor <gegrigor@student.42yerevan.am>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/01/27 16:52:16 by gegrigor		   #+#	  #+#			  */
/*	 Updated: 2026/01/27 22:26:41 by gegrigor		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeprev(char **arr, size_t i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static char	*fill_word(char const *s, size_t start, size_t end)
{
	char		*word;
	size_t		k;

	k = 0;
	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	while (start < end)
		word[k++] = s[start++];
	word[k] = '\0';
	return (word);
}

static int	get_word(char const *s, int c, char **p)
{
	size_t		i;
	size_t		j;
	size_t		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			p[j] = fill_word(s, start, i);
			if (!p[j])
				return (ft_freeprev(p, j), 0);
			j++;
		}
	}
	p[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	if (!get_word(s, c, p))
		return (NULL);
	return (p);
}
