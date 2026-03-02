/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:11:26 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/02 18:41:43 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack **a)
{
    t_stack *i;
    t_stack *j;

    i = *a;
   
    while (i && i->next)
    {
        j = i->next;
        if (i->value > j->value)
            return (0);
        i = i->next;
    }
    return (1);
}

static float   compute_disorder(t_stack **a)
{
    int mistakes;
    int total_pairs;
    t_stack *i;
    t_stack *j;

    mistakes = 0;
    total_pairs = 0;
    i = (*a);
    while (i)
    {
        j = i->next;
        while (j)
        {
            total_pairs += 1;
            if (i->value > j->value)
                mistakes +=1;
            j = j->next;
        }
        i = i->next;
    }
    return ((float)mistakes / total_pairs);
}

void    sorter(t_stack **a, t_stack **b, int n, t_mode *mode)
{
    float   disorder;
    
    if (is_sorted(a))
        return ;
    if (mode->sorter == ADAPTIVE)
    {
        if (n == 2)
        {
            sort_two(a);
            return ;
        }
        else if (n == 3)
        {
            sort_three(a);
            return ;
        }
        else if (n == 5)
        {
            sort_five(a, b);
            return ;
        }
        else
        {
            disorder = compute_disorder(a);
            if (disorder < 0.2)
                mode->sorter = SIMPLE;
            else if (disorder >= 0.2 && disorder < 0.5)
                mode->sorter = MEDIUM;
            else 
                mode->sorter = COMPLEX;
        }
    }
    else if (mode->sorter == SIMPLE)
    {
        bubble_sort(a);
    }
    else if (mode->sorter == MEDIUM)
    {
        radix_sort(a, b, n);
    }
    else if (mode->sorter == COMPLEX)
    {
        radix_sort(a, b, n);
        printf("dfdfgds");
    }
    if (mode->bench == ON)
    {}
}