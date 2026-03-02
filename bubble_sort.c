/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:15:08 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/01 16:08:29 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    bubble_sort(t_stack **a)
{
    int size;
    int sorted;
    int i;

    size = stack_size(*a);
    sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        i = 0;
        while (i < size)
        {
            if (i < size - 1)
            {
                if ((*a)->value > (*a)->next->value)
                {
                    sorted = 0;
                    sa(a);
                }
            }
            ra(a);
                i++;
        }
    }    
}