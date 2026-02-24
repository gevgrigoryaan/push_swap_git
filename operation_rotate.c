/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:22:52 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/24 17:03:20 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rotate(t_stack **head)
{
    t_stack *tmp;

    tmp = (*head);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = (*head);
    (*head) = (*head)->next;
    tmp->next->next = NULL;
}

void    rotate_a(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rotate_b(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rotate_ab(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}