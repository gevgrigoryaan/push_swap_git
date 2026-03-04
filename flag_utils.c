/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:30:49 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/04 18:32:00 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mode	*init_flags(void)
{
	t_mode	*mode;

	mode = malloc(sizeof(t_mode));
	if (!mode)
		return (NULL);
	mode->sorter = ADAPTIVE;
	mode->bench = OFF;
	return (mode);
}

int	check_bench(char *args, t_mode *mode)
{
	if (!args)
		return (0);
	if (ft_strncmp(args, "--bench", 7) == 0)
		return (mode->bench = ON, 1);
	return (0);
}

int	check_flags(char *argv, t_mode *mode)
{
	if (!argv)
		return (0);
	if (ft_strncmp(argv, "--simple", ft_strlen(argv)) == 0)
		return (mode->sorter = SIMPLE, 1);
	else if (ft_strncmp(argv, "--medium", 8) == 0)
		return (mode->sorter = MEDIUM, 1);
	else if (ft_strncmp(argv, "--complex", 9) == 0)
		return (mode->sorter = COMPLEX, 1);
	else if (ft_strncmp(argv, "--adaptive", 10) == 0)
		return (mode->sorter = ADAPTIVE, 1);
	else
		return (0);
}

int	flags(char **args, t_mode *mode)
{
	int	i;

	i = 0;
	if (check_flags(args[0], mode))
	{
		if (args[1] && check_flags(args[1], mode))
			exit_error();
		if (args[1] && check_bench(args[1], mode))
			i++;
		i++;
	}
	else if (check_bench(args[0], mode))
	{
		if (args[1] && check_bench(args[1], mode))
			exit_error();
		if (args[1] && check_flags(args[1], mode))
			i++;
		i++;
	}
	return (i);
}
