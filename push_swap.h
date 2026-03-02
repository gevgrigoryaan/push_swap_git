/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:48:02 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/02 18:02:28 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>   

# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define ADAPTIVE 4
# define ON 1
# define OFF 0

typedef struct s_stack
{
    int				value;
    int             index;
    struct s_stack	*next;
}	t_stack;

typedef struct s_mode
{
    int sorter;
    int bench;
}   t_mode;

/* operations */

void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **b, t_stack **a);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* algorithms */

void    bubble_sort(t_stack **a);
void    radix_sort(t_stack **a, t_stack **b, int n);
void    sorter(t_stack **a, t_stack **b, int n, t_mode *mode);
void    sort_five(t_stack **a, t_stack **b);
void    sort_three(t_stack **a);
void    sort_two(t_stack **a);



int     stack_size(t_stack *a);
void    free_stack(t_stack *stack);
void    exit_error(void);
char    **get_args(int argc, char **argv);
char    *ft_strjoin_free(char *s1, char *s2);
t_stack	*fill_stack_values(char **args);
void	stack_add_bottom(t_stack **stack, t_stack *new);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*stack_new(int value);
int	    get_max(t_stack **a);
int	    get_min(t_stack **a);
int     get_median(t_stack **a);
long	ft_atoi_long(const char *str);
char    *ft_strtrim_free(char *s1, char *set);




#endif