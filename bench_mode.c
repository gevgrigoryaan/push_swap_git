/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:04:56 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/07 23:04:31 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	complexity(float disorder, t_mode *mode)
{
	if (disorder < 0.2 && mode->sorter == ADAPTIVE)
		return (5);
	else if (disorder >= 0.2 && disorder < 0.5 && mode->sorter == ADAPTIVE)
		return (6);
	else if (disorder >= 0.5 && mode->sorter == ADAPTIVE)
		return (7);
	else
		return (mode->sorter + 4);
}

void	init_strategy(char **strategy)
{
	strategy[0] = "h";
	strategy[1] = "Simple";
	strategy[2] = "Medium";
	strategy[3] = "Complex";
	strategy[4] = "Adaptive";
	strategy[5] = "O(n²)";
	strategy[6] = "O(n√n)";
	strategy[7] = "O(nlog(n))";
}

void	bench_mode(float disorder, int real_mode, t_count *count, t_mode *mode)
{
	int		sum;
	int		dis_i;
	int		dis_p;
	char	*strategy[8];

	init_strategy(strategy);
	dis_i = (int)(disorder * 100);
	dis_p = (int)(disorder * 10000) % 100;
	sum = count->op_sa + count->op_sb + count->op_ss + count->op_pa
		+ count->op_pb + count->op_ra + count->op_rb + count->op_rr
		+ count->op_rra + count->op_rrb + count->op_rrr;
	ft_printf("[bench] disorder:    %d.%d%%\n"
		"[bench] strategy:  %s / %s\n"
		"[bench] total ops:  %d\n"
		"[bench] sa: %i  sb: %i  ss: %i  pa:    %i  pb: %i\n"
		"[bench] ra: %i  rb: %i  rr: %i  "
		"rra:    %i  rrb:   %i  rrr:   %i\n",
		dis_i, dis_p, strategy[real_mode], strategy[complexity(disorder, mode)],
		sum, count->op_sa, count->op_sb, count->op_ss, count->op_pa,
		count->op_pb, count->op_ra, count->op_rb, count->op_rr,
		count->op_rra, count->op_rrb, count->op_rrr);
	free(count);
}
