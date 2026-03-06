/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:12:49 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/06 18:26:21 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *a, int n)
{
	int	max;
	int	i;

	i = 1;
	max = a->value;
	a = a->next;
	while (i < n)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
		i++;
	}
	return (max);
}

int	get_2nd_min(t_stack *a, int n)
{
	int	min;
	int	i;
	int	min_2nd;

	i = 1;
	min = get_min(a, 5);
	if (a->value == min)
		a = a->next;
	min_2nd = a->value;
	a = a->next;
	while (i < n && a)
	{
		if (a->value != min && a->value < min_2nd)
			min_2nd = a->value;
		a = a->next;
		i++;
	}
	return (min_2nd);
}

int	get_min(t_stack *a, int n)
{
	int	min;
	int	i;

	i = 1;
	min = a->value;
	a = a->next;
	while (i < n && a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
		i++;
	}
	return (min);
}

int	get_median(t_stack **a, int n)
{
	int	max;
	int	min;

	max = get_max(*a, n);
	min = get_min(*a, n);
	return (min + (max - min) / 2);
}

/*
void	partition(t_stack **a, t_stack **b, int n, t_count *count)
{
	int	pivot;
	int	first_greater;
	int	i;
	int	max_rotations = n;
	int	rotations = 0;


	pivot = get_median(a, n);
	first_greater = pivot;
	i = 0;
	while (i < n)
	{
		if ((*a)->value <= pivot)
			pb(a, b, count);
		else
		{
			if (first_greater == pivot)
				first_greater = (*a)->value;
			ra(a, count);
		}
		i++;
	}
	while ((*a)->value != first_greater && rotations < max_rotations)
	{
		rra(a, count);
		rotations++;
	}
	while ((*b)->value != pivot)
		rb(b, count);
	while (*b)
		pa(a, b, count);
}

void	quick_sort(t_stack **a, t_stack **b, int n, t_count *count)
{
	int	i;

	if (n == 2)
	{
		sort_two(a, count);
	}
	else if (n > 2)
	{
		partition(a, b, n, count);
		quick_sort(a, b, (n - 1) / 2, count);
		i = 0;
		while (i < n - n / 2)
		{
			ra(a, count);
			i++;
		}
		quick_sort(a, b, (n - 1) - ((n - 1) / 2), count);
		i = 0;
		while (i < n - n / 2)
		{
			rra(a, count);
			i++;
		}
	}

*/