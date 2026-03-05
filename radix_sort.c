/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:45:10 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/06 00:09:37 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *a, int n)
{
	t_stack	*sorted;

	sorted = dup_stack(a);
	bubble_sort_stack(sorted, n);
	give_indices(a, sorted);
}

void	give_indices(t_stack *a, t_stack *sorted)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		temp->index = find_position_in_sorted(temp->value, sorted);
		temp = temp->next;
	}
	free_stack(sorted);
}

void	radix_sort(t_stack **a, t_stack **b, int n, t_count *count)
{
	int	bits;
	int	i;

	bits = 1;
	assign_indices(*a, n);
	while (bits <= n - 1)
	{
		i = 0;
		while (i < n)
		{
			if (!((*a)->index & bits))
				pb(a, b, count);
			else
				ra(a, count);
			i++;
		}
		while (*b)
			pa(a, b, count);
		bits = bits << 1;
	}
}
