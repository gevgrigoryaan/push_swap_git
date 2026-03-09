/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:48:02 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/09 13:07:19 by gegrigor         ###   ########.fr       */
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
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_mode
{
	int	sorter;
	int	bench;
}	t_mode;

/*  for bench mode  */

typedef struct s_count
{
	int	op_sa;
	int	op_sb;
	int	op_ss;
	int	op_pa;
	int	op_pb;
	int	op_ra;
	int	op_rb;
	int	op_rr;
	int	op_rra;
	int	op_rrb;
	int	op_rrr;
}	t_count;

/* operations */

void	sa(t_stack **a, t_count *count);
void	sb(t_stack **b, t_count *count);
void	ss(t_stack **a, t_stack **b, t_count *count);
void	pa(t_stack **b, t_stack **a, t_count *count);
void	pb(t_stack **a, t_stack **b, t_count *count);
void	ra(t_stack **a, t_count *count);
void	rb(t_stack **b, t_count *count);
void	rr(t_stack **a, t_stack **b, t_count *count);
void	rra(t_stack **a, t_count *count);
void	rrb(t_stack **b, t_count *count);
void	rrr(t_stack **a, t_stack **b, t_count *count);

/*  checker operations  */

void	sa_bonus(t_stack **a);
void	sb_bonus(t_stack **b);
void	ss_bonus(t_stack **a, t_stack **b);
void	pa_bonus(t_stack **b, t_stack **a);
void	pb_bonus(t_stack **a, t_stack **b);
void	ra_bonus(t_stack **a);
void	rb_bonus(t_stack **b);
void	rr_bonus(t_stack **a, t_stack **b);
void	rra_bonus(t_stack **a);
void	rrb_bonus(t_stack **b);
void	rrr_bonus(t_stack **a, t_stack **b);

/* algorithms */

void	bubble_sort(t_stack **a, t_count *count);
void	chunk_sort(t_stack **a, t_stack **b, int n, t_count *count);
void	radix_sort(t_stack **a, t_stack **b, int n, t_count *count);
void	sorter(t_stack **a, t_stack **b, int n, t_mode *mode);
void	sort_five(t_stack **a, t_stack **b, t_count *count);
void	sort_three(t_stack **a, t_count *count);
void	sort_two(t_stack **a, t_count *count);

/*  stack utils  */

int		stack_size(t_stack *a);
void	free_stack(t_stack *stack);
void	exit_error(void);
char	**get_args(int argc, char **argv);
char	*ft_strjoin_free(char *s1, char *s2);
t_stack	*fill_stack_values(char **args);
void	stack_add_bottom(t_stack **stack, t_stack *new);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*stack_new(int value);
int		get_min(t_stack *a, int n);
int		get_2nd_min(t_stack *a, int n);
long	ft_atoi_long(const char *str);
char	*ft_strtrim_free(char *s1, char *set);
t_count	*init_count(void);
void	give_indices(t_stack *a, t_stack *sorted);
int		find_position_in_sorted(int value, t_stack *sorted);
t_stack	*dup_stack(t_stack *head);
void	bubble_sort_stack(t_stack *sorted, int n);
void	bench_mode(float disorder, int real_mode, t_count *count, t_mode *mode);
int		is_sorted(t_stack *a);
void	assign_indices(t_stack *a, int n);
void	check_dups(t_stack *a);

/*  validation checkers  */

t_mode	*init_flags(void);
int		check_bench(char *args, t_mode *mode);
int		check_flags(char *argv, t_mode *mode);
int		flags(char **args, t_mode *mode);
int		is_valid(char **args, int n);


#endif
