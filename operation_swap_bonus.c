/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:58:07 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/05 20:14:13 by gegrigor         ###   ########.fr       */
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

void	sa_bonus(t_stack **a)
{
	swap(a);
}

void	sb_bonus(t_stack **b)
{
	swap(b);
}

void	ss_bonus(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
