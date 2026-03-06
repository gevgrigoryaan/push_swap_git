/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:09:38 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/06 14:50:08 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dups(t_stack *a)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		n;

	n = stack_size(a);
	i = 0;
	while (i < n)
	{
		tmp = a->next;
		j = i + 1;
		while (j < n)
		{
			if (a->value == tmp->value)
				exit_error();
			j++;
			tmp = tmp->next;
		}
		i++;
		a = a->next;
	}
}
