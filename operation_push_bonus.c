/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:14:09 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 20:14:13 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!from || !(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

void	pa_bonus(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	pb_bonus(t_stack **a, t_stack **b)
{
	push(a, b);
}
