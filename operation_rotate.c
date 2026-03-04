/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:22:52 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/04 18:42:39 by gegrigor         ###   ########.fr       */
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

void	ra(t_stack **a, t_count *count)
{
	rotate(a);
	write(1, "ra\n", 3);
	count->op_ra += 1;
}

void	rb(t_stack **b, t_count *count)
{
	rotate(b);
	write(1, "rb\n", 3);
	count->op_rb += 1;
}

void	rr(t_stack **a, t_stack **b, t_count *count)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	count->op_rr += 1;
}
