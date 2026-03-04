/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:33:45 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/04 18:35:34 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_in_sorted(int value, t_stack *sorted)
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

t_stack	*dup_stack(t_stack *head)
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
	new_head->next = NULL;
	current = head->next;
	new_node = new_head;
	while (current)
	{
		new_node->next = malloc(sizeof(t_stack));
		if (!new_node->next)
			return (free_stack(new_head), NULL);
		new_node = new_node->next;
		new_node->value = current->value;
		new_node->next = NULL;
		current = current->next;
	}
	return (new_head);
}

void	bubble_sort_stack(t_stack *sorted, int n)
{
	t_stack	*temp;
	int		swapped;
	int		i;
	int		swap;

	i = 0;
	swapped = 1;
	while (i++ < n - 1 && swapped)
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
}
