/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:48:02 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/24 17:03:25 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int				value;
    int             index;
    struct s_stack	*next;
}	t_stack;

/* operations */

void    swap_a(t_stack **a);
void    swap_b(t_stack **b);
void    swap_ab(t_stack **a, t_stack **b);
void    push_a(t_stack **b, t_stack **a);
void    push_b(t_stack **a, t_stack **b);
void    rotate_a(t_stack **a);
void    rotate_b(t_stack **b);
void    rotate_ab(t_stack **a, t_stack **b);
void	r_rotate_a(t_stack **a);
void	r_rotate_b(t_stack **b);
void	r_rotate_ab(t_stack **a, t_stack **b);



#endif