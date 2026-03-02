/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:31:04 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/02 19:32:12 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *a)
{
    int size;

    if (!a)
        return 0;
    size = 1;
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

void exit_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

t_stack	*fill_stack_values(char **args)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 10)
			exit_error();
		nb = ft_atoi_long(args[i]);
		free(args[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error();
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
char *ft_strjoin_free(char *s1, char *s2)
{
    char *p;

    p = ft_strjoin(s1, s2);
    free(s1);
    return (p);
}

char *ft_strtrim_free(char *s1, char *set)
{
	char *p;

	p = ft_strtrim(s1, set);
	free(s1);
	return (p);
}

char **get_args(int argc, char **argv)
{
    char *argstr;
    char **result;
    int i;
    
    i = 1;
    argstr = ft_strdup("");
    while (i < argc)
    {
        argstr = ft_strjoin_free(argstr, " ");
        argstr = ft_strjoin_free(argstr, argv[i]);
        i++;
    }
    result = ft_split(argstr, ' ');
    free(argstr);
    return (result);
}

int	get_max(t_stack **a)
{
	int max;
	t_stack *tmp;

	tmp = *a;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack **a)
{
	int min;
	t_stack *tmp;

	tmp = *a;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int get_median(t_stack **a)
{
	int	max;
	int	min;

	max = get_max(a);
	min = get_min(a);
	return (min + (max - min) / 2);
}