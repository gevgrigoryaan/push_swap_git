/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:31:04 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/04 19:18:05 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*p;

	p = ft_strjoin(s1, s2);
	free(s1);
	return (p);
}

char	*ft_strtrim_free(char *s1, char *set)
{
	char	*p;

	p = ft_strtrim(s1, set);
	free(s1);
	return (p);
}

char	**get_args(int argc, char **argv)
{
	char	*argstr;
	char	**result;
	int		i;

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
