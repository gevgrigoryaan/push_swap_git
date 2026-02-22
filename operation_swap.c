/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:58:07 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/22 17:58:07 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    swap_stack(t_stack **stack)
{
    t_stack    *tmp;

    tmp = stack->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;

}