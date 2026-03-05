/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:54:49 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/06 00:21:59 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fine_pos_indexov(t_stack *s, int index)
{
	int	pos;

	pos = 0;
	while (s)
	{
		if (s->index == index)
			return (pos);
		s = s->next;
		pos++;
	}
	return (-1);
}

static void	push_chunks(t_stack **a, t_stack **b, t_count *count, int chunk)
{
	int	current;

	current = 0;
	while (*a)
	{
		if ((*a)->index <= current)
		{
			pb(a, b, count);
			rb(b, count);
			current++;
		}
		else if ((*a)->index <= current + chunk)
		{
			pb(a, b, count);
			current++;
		}
		else
			ra(a, count);
	}
}

static int	move_top_from_b(t_stack **b, int index, t_count *count)
{
	int	pos;
	int	rot;

	pos = fine_pos_indexov(*b, index);
	if (pos < 0)
		return (0);
	if (pos <= stack_size(*b) / 2)
	{
		rot = pos;
		while (rot-- > 0)
			rb(b, count);
	}
	else
	{
		rot = stack_size(*b) - pos;
		while (rot-- > 0)
			rrb(b, count);
	}
	return (1);
}

static void	lc_back(t_stack **a, t_stack **b, int n, t_count *count)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		if (!move_top_from_b(b, i, count))
		{
			i--;
			continue ;
		}
		pa(a, b, count);
		i--;
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int n, t_count *count)
{
	int	chunk_size;

	if (!a || !*a || n <= 1)
		return ;
	assign_indices(*a, n);
	chunk_size = 1;
	while (chunk_size * chunk_size < n)
		chunk_size++;
	push_chunks(a, b, count, chunk_size);
	lc_back(a, b, n, count);
}
