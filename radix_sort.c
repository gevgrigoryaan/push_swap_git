/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:45:10 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/26 20:42:22 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_position_in_sorted(int value, t_stack *sorted)
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

static t_stack	*dup_stack(t_stack *head)
{
	t_stack	*new_head;
	t_stack	*new_node;
	t_stack	*current;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(t_stack));
	if (!new_head)
		return (NULL);
	new_head->value = head->value;
	new_head->index = head->index;
	new_head->next = NULL;
	current = head->next;
	new_node = new_head;
	while (current)
	{
		new_node->next = malloc(sizeof(t_stack));
		if (!new_node->next)
		{
			free_stack(new_head);
			return (NULL);
		}
		new_node = new_node->next;
		new_node->value = current->value;
		new_node->index = current->index;
		new_node->next = NULL;
		current = current->next;
	}
	return (new_head);
}

static void	assign_indices(t_stack *a, int n)
{
	t_stack	*current;
	t_stack	*temp;
	t_stack	*sorted;
	int		swapped;
	int		i;
	int		swap;

	sorted = dup_stack(a);
	i = 0;
	while (i < n - 1)
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
		if (!swapped)
			break ;
		i++;
	}
	current = a;
	while (current)
	{
		current->index = find_position_in_sorted(current->value, sorted);
		current = current->next;
	}
	free_stack(sorted);
}

void	radix_sort(t_stack **a, t_stack **b, int n)
{
	int bits;
	int i;

	bits = 1;
	while (bits <= n - 1)
	{
		i = 0;
		while (i < n)
		{
			if (!((*a)->index & bits))
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (!*b)
			pa(a, b);
		bits = bits << 1;
	}
}