/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gegrigor <gegrigor@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:03:28 by gegrigor          #+#    #+#             */
/*   Updated: 2026/02/08 15:59:57 by gegrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!f || !lst)
		return ;
	tmp = lst;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
	lst = tmp;
}
/*
int main()
{
	t_list *list;
	ft_lstiter(list, NULL);
	return 0;
}
*/
