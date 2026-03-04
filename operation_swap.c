/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:58:07 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/02 19:58:15 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !((*head)->next))
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	sa(t_stack **a, t_count *count)
{
	swap(a);
	write(1, "sa\n", 3);
	count->op_sa += 1;
}

void	sb(t_stack **b, t_count *count)
{
	swap(b);
	write(1, "sb\n", 3);
	count->op_sb += 1;
}

void	ss(t_stack **a, t_stack **b, t_count *count)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	count->op_ss += 1;
}
