/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:14:39 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/04 18:31:04 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	t_mode	*mode;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	args = get_args(argc, argv);
	mode = init_flags();
	i += flags(args, mode);
	if (!is_valid(args + i, argc - i - 1))
		exit_error();
	a = fill_stack_values(args + i);
	b = NULL;
	free(args);
	sorter(&a, &b, stack_size(a), mode);
	free_stack(a);
	free_stack(b);
	return (0);
}
