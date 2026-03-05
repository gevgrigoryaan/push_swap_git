/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:54:49 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 20:54:50 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*lc_stuck_loc(t_stack *head)
{
	t_stack	*new_head;
	t_stack	*tmp;

	if (!head)
		return (NULL);
	new_head = stack_new(head->value);
	if (!new_head)
		return (NULL);
	head = head->next;
	while (head)
	{
		tmp = stack_new(head->value);
		if (!tmp)
			return (new_head);
		stack_add_bottom(&new_head, tmp);
		head = head->next;
	}
	return (new_head);
}

static int	finde_pos_sort_loc(int value, t_stack *sorted)
{
	int	index;

	index = 0;
	while (sorted)
	{
		if (value == sorted->value)
			return (index);
		sorted = sorted->next;
		index++;
	}
	return (-1);
}

static void	indices_local(t_stack *a)
{
	t_stack	*current;
	t_stack	*temp;
	t_stack	*sorted;
	int		swapped;
	int		swap;

	sorted = lc_stuck_loc(a);
	if (!sorted)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		temp = sorted;
		while (temp && temp->next)
		{
			if (temp->value > temp->next->value)
			{
				swap = temp->value;
				temp->value = temp->next->value;
				temp->next->value = swap;
				swapped = 1;
			}
			temp = temp->next;
		}
	}
	current = a;
	while (current)
	{
		current->index = finde_pos_sort_loc(current->value, sorted);
		current = current->next;
	}
	free_stack(sorted);
}

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

static int	get_chunk_size(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
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

static void	lc_back(t_stack **a, t_stack **b, int n, t_count *count)
{
	int	i;
	int	size_b;
	int	pos;
	int	rot;

	i = n - 1;
	while (i >= 0)
	{
		size_b = stack_size(*b);
		pos = fine_pos_indexov(*b, i);
		if (pos < 0)
		{
			i--;
			continue ;
		}
		if (pos <= size_b / 2)
		{
			rot = pos;
			while (rot-- > 0)
				rb(b, count);
		}
		else
		{
			rot = size_b - pos;
			while (rot-- > 0)
				rrb(b, count);
		}
		pa(a, b, count);
		i--;
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int n, t_count *count)
{
	int	chunk;

	if (!a || !*a || n <= 1)
		return ;
	indices_local(*a);
	chunk = get_chunk_size(n);
	push_chunks(a, b, count, chunk);
	lc_back(a, b, n, count);
}
