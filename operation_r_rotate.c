/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:33:23 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/24 17:03:19 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    r_rotate(t_stack **head)
{
    t_stack *tail;
    t_stack *new_tail;

    if (!(*head) || !((*head)->next))
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

void    r_rotate_a(t_stack **a)
{
    r_rotate(a);
    write(1, "rra\n", 3);
}

void    r_rotate_b(t_stack **b)
{
    r_rotate(b);
    write(1, "rrb\n", 3);
}
void    r_rotate_ab(t_stack **a, t_stack **b)
{
    r_rotate(a);
    r_rotate(b);
    write(1, "rrr\n", 3);
}