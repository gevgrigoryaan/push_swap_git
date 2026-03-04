/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:06:15 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/04 18:41:41 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_count *count)
{
	sa(a, count);
}

void	sort_three(t_stack **a, t_count *count)
{
	t_stack	*tmp;

	tmp = *a;
	if (!tmp || !tmp->next || !tmp->next->next)
		return ;
	if (tmp->value < tmp->next->value && tmp->value < tmp->next->next->value)
	{
		rra(a, count);
		sa(a, count);
	}
	else if (tmp->value > tmp->next->value
		&& tmp->value > tmp->next->next->value)
	{
		ra(a, count);
		if ((*a)->value > (*a)->next->value)
			sa(a, count);
	}
	else if (tmp->next->value > tmp->next->next->value)
		rra(a, count);
	else
		sa(a, count);
}

void	sort_five(t_stack **a, t_stack **b, t_count *count)
{
	int		pivot;
	int		i;
	t_stack	*tmp;

	pivot = get_median(a);
	i = 0;
	while (i < 5)
	{
		tmp = *a;
		if (!tmp)
			break ;
		if (tmp->value < pivot)
			pb(a, b, count);
		else
			ra(a, count);
		i++;
	}
	tmp = *b;
	if (tmp && tmp->next && tmp->value > tmp->next->value)
		sb(b, count);
	sort_three(a, count);
	pa(a, b, count);
	pa(a, b, count);
}
