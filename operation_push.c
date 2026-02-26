/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:14:09 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/26 20:22:03 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    push(t_stack **from, t_stack **to)
{
    t_stack *tmp;

    if (!from || !(*from))
        return ;
    tmp = *from;
    *from = (*from)->next;
    if (!to)
        *to = tmp;
    else
    {
        tmp->next = *to;
        *to = tmp;
    }
}

void    pa(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}