/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:31:04 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/25 18:33:34 by gegrigor         ###   ########.fr       */
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