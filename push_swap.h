/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:48:02 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/03 17:33:20 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define ADAPTIVE 4
# define ON 1
# define OFF 0

# define INT_MIN -2147483648
# define INT_MAX 2147482647

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

typedef struct s_count
{
    int op_sa;
    int op_sb;
    int op_ss;
    int op_pa;
    int op_pb;
    int op_ra;
    int op_rb;
    int op_rr;
    int op_rra;
    int op_rrb;
    int op_rrr;
}   t_count;

/* operations */

void    sa(t_stack **a, t_count *count);
void    sb(t_stack **b, t_count *count);
void    ss(t_stack **a, t_stack **b, t_count *count);
void    pa(t_stack **b, t_stack **a, t_count *count);
void    pb(t_stack **a, t_stack **b, t_count *count);
void    ra(t_stack **a, t_count *count);
void    rb(t_stack **b, t_count *count);
void    rr(t_stack **a, t_stack **b, t_count *count);
void	rra(t_stack **a, t_count *count);
void	rrb(t_stack **b, t_count *count);
void	rrr(t_stack **a, t_stack **b, t_count *count);

/* algorithms */

void    bubble_sort(t_stack **a, t_count *count);
void    radix_sort(t_stack **a, t_stack **b, int n, t_count *count);
void    sorter(t_stack **a, t_stack **b, int n, t_mode *mode, t_count *count);
void    sort_five(t_stack **a, t_stack **b, t_count *count);
void    sort_three(t_stack **a, t_count *count);
void    sort_two(t_stack **a, t_count *count);



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
t_count *init_count(void);


int	ft_printf(char const *formar, ...);
int	ft_putchar(char c);
int	ft_putnbr(long nb);
int	ft_putnbr_hexa(unsigned long nbr, char up);
int	ft_putptr(void *p);
int	ft_putstr(char *s);






#endif