/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:31:04 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/26 20:22:03 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *a)
{
    int size;

    if (!a)
        return ;
    size = 0;
    while (a->next)
    {
        a = a->next;
        size++;
    }
    return (size);
}

void    free_stack(t_stack *stack)
{
    t_stack *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}