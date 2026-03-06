/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:34:19 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/06 15:03:16 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "push_swap.h"
#include <limits.h>

int	is_sorted(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;

	i = a;
	while (i && i->next)
	{
		j = i->next;
		if (i->value > j->value)
			return (0);
		i = i->next;
	}
	return (1);
}

static void	do_operations(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa_bonus(a);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb_bonus(b);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss_bonus(a, b);
	else if (!ft_strncmp(op, "pa\n", 3))
		pa_bonus(a, b);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb_bonus(a, b);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra_bonus(a);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb_bonus(b);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr_bonus(a, b);
	else if (!ft_strncmp(op, "rra\n", 4))
		rra_bonus(a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrb_bonus(b);
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr_bonus(a, b);
	else
		exit_error();
}

static void	read_operations(t_stack **a, t_stack **b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		do_operations(a, b, op);
		free(op);
		op = get_next_line(0);
	}
}

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
	read_operations(&a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return (0);
}
