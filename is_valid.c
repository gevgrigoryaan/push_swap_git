/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:16:53 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 21:14:23 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	r = r * s;
	return (r);
}

int	is_nbr(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '-' && args[i][1] == '0')
			args[i] = ft_strtrim_free(args[i], "-");
		j = 0;
		if (args[i][j] == '+' || args[i][j] == '-')
		{
			if (args[i][j] == '+')
				args[i] = ft_strtrim_free(args[i], "+");
			else
				j++;
		}
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid(char **args, int n)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < n)
	{
		if (!args[i] || !is_nbr(args))
			return (0);
		i++;
	}
	i = 0;
	while (args[i])
	{
		tmp = args[i];
		j = i + 1;
		while (args[j])
		{
			if (ft_strncmp(tmp, args[j], 11) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
