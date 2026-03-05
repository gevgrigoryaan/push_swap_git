/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:33:23 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 20:14:13 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack **head)
{
	t_stack	*tail;
	t_stack	*new_tail;

	if (!(*head) || !((*head)->next))
		return ;
	tail = (*head);
	while (tail->next)
	{
		new_tail = tail;
		tail = tail->next;
	}
	tail->next = (*head);
	new_tail->next = NULL;
	*head = tail;
}

void	rra_bonus(t_stack **a)
{
	r_rotate(a);
}

void	rrb_bonus(t_stack **b)
{
	r_rotate(b);
}

void	rrr_bonus(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
}
