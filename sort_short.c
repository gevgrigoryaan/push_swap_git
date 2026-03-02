/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:06:15 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/01 18:28:57 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two(t_stack **a)
{
    sa(a);
}

void    sort_three(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    if (!tmp || !tmp->next || !tmp->next->next)
        return ;
    if (tmp->value < tmp->next->value && tmp->value < tmp->next->next->value)
	{
		rra(a);
		sa(a);
		return ;
	}
	else if (tmp->value > tmp->next->value && tmp->value > tmp->next->next->value)
	{
		ra(a);
		tmp = *a;
		if (tmp->value > tmp->next->value)
			sa(a);
	}
	else
	{
		if (tmp->next->value > tmp->next->next->value)
			rra(a);
		else
			sa(a);
	}
}

void    sort_five(t_stack **a, t_stack **b)
{
    int	pivot;
	int	i;
    t_stack *tmp;

	pivot = get_median(a);
	i = 0;
	while (i < 5)
	{
		tmp = *a;
		if (!tmp)
			break;
		if (tmp->value < pivot)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	tmp = *b;
	if (tmp && tmp->next && tmp->value > tmp->next->value)
		sb(b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}