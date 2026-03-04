/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:33:23 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/04 18:42:25 by gegrigor         ###   ########.fr       */
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

void	rra(t_stack **a, t_count *count)
{
	r_rotate(a);
	write(1, "rra\n", 4);
	count->op_rra += 1;
}

void	rrb(t_stack **b, t_count *count)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
	count->op_rrb += 1;
}

void	rrr(t_stack **a, t_stack **b, t_count *count)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
	count->op_rrr += 1;
}
