/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gevgrigoryaan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:14:39 by gegrigor          #+#    #+#             */
/*   Updated: 2026/03/03 17:34:50 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static t_mode *init_flags()
{
    t_mode *mode;
    
    mode = malloc(sizeof(t_mode));
    if (!mode)
        return (NULL);
    mode->sorter = ADAPTIVE;
    mode->bench = OFF;
    return (mode);
}

static int check_bench(char *args, t_mode *mode)
{
    if (!args)
        return (0);
    if (ft_strncmp(args, "--bench", 7) == 0)
        return (mode->bench = ON, 1);
    return (0);
}

static int  check_flags(char *argv, t_mode *mode)
{
    if (!argv)
        return (0);
	if (ft_strncmp(argv, "--simple", ft_strlen(argv)) == 0)
		return (mode->sorter = SIMPLE , 1);
	else if (ft_strncmp(argv, "--medium", 8) == 0)
		return (mode->sorter = MEDIUM, 1);
	else if (ft_strncmp(argv, "--complex", 9) == 0)
        return (mode->sorter = COMPLEX, 1);
	else if (ft_strncmp(argv, "--adaptive", 10) == 0)
		return (mode->sorter = ADAPTIVE, 1);
    else
	    return (0);
}
static int flags(char **args, t_mode *mode)
{
    int i = 0;
    if (check_flags(args[0], mode))
    {
        if (args[1] && check_flags(args[1], mode))
            exit_error();
        if (args[1] && check_bench(args[1], mode))
            i++;
        i++;
    }
    else if (check_bench(args[0], mode))
    {
        if (args[1] && check_bench(args[1], mode))
            exit_error();
        if (args[1] && check_flags(args[1], mode))
            i++;
        i++;
    }
    return (i);
}
static int is_valid(char **args, int n)
{
    int i;
    int j;
    char *tmp;

    i = 0;
    while (i < n)
    {
        if (!args[i])
            return (0);
        i++;
    }
    i = 0;
    while (args[i])
    {
        j = 0;
        if (args[i][j] == '+' || args[i][j] == '-')
        {
            if (args[i][j] == '+')
                args[i] = ft_strtrim_free(args[i], "+");
            else 
                j++;
        }
        while (args[i][j])
        {
            if (!ft_isdigit(args[i][j])) ///poxi isdigity is number INT_MIN<<INT_MAX
                return (0);
            j++;
        }
        i++;
    }
    i = 0;
    while (args[i])
    {
        tmp = args[i];
        j = i + 1;
        while (args[j])
        {
            if (ft_strncmp(tmp, args[j], 11) == 0)
                return (0);
            j++;
        }
        i++;
        
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    char **args;
    t_mode *mode;
    int i;
    t_count *count;
    
    i = 0;
    if (argc < 2)
        return (0);
    args = get_args(argc, argv);
    mode = init_flags();
    i += flags(args, mode);
    if (!is_valid(args + i, argc - i - 1))
        exit_error();
    a = fill_stack_values(args + i);
    b = NULL;
    free(args);
    int n = stack_size(a);
    count = init_count();
    sorter(&a, &b, n, mode, count);
    free(count);
    free_stack(a);
    free_stack(b);
    // printf("%i\n", mode->sorter);
    // printf("%i\n", mode->bench);
    // bubble_sort(&a);
    // radix_sort(&a, &b, n);
    // while (*args)
    // {
    //     printf("%s\n", *args);
    //     args++;
    // }
    return (0);
}