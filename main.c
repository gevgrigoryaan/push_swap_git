/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:17:36 by rafhovha          #+#    #+#             */
/*   Updated: 2026/02/26 20:22:03 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	check_flag(char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0)
		return (1);
	else if (ft_strcmp(argv, "--medium") == 0)
		return (2);
	else if (ft_strcmp(argv, "--complex") == 0)
		return (3);
	else if (ft_strcmp(argv, "--adaptive") == 0)
		return (4);
	else
		return (4);
}

static int	check_str(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			write (1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	checker(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 2)
	{
		while (i <= argc)
		{
			if (check_flag(argv[i]))
			{
				i++;
				continue ;
			}
			if (!(check_str(argv[i])))
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		if (!check_flag(argv[i]))
		{
			
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int	mode;

	if (argc < 2)
		return (0);
	mode = check_flag(argv[1]);
	a = parse_numbers(argc, argv);
	b = NULL;
	sort(a, b, mode);
	free_stack(a);
}
