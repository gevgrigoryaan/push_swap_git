/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:22:52 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 20:14:13 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*head);
	(*head) = (*head)->next;
	tmp->next->next = NULL;
}

void	ra_bonus(t_stack **a)
{
	rotate(a);
}

void	rb_bonus(t_stack **b)
{
	rotate(b);
}

void	rr_bonus(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
