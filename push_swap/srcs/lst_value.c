/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:41:36 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/03 08:44:29 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_value	ft_stack_search_lower(t_stack *begin_a)
{
	t_stack	*lst;
	int		i;
	t_value	lower;

	i = 2;
	lower.value = begin_a->number;
	lower.index = 1;
	lst = begin_a->next;
	while (lst != begin_a)
	{
		if (lst->number < lower.value)
		{
			lower.value = lst->number;
			lower.index = i;
		}
		lst = lst->next;
		i++;
	}
	return (lower);
}

t_value	ft_stack_search_bigger(t_stack *begin_a)
{
	t_stack	*lst;
	int		i;
	t_value	bigger;

	i = 2;
	bigger.value = begin_a->number;
	bigger.index = 1;
	lst = begin_a->next;
	while (lst != begin_a)
	{
		if (lst->number > bigger.value)
		{
			bigger.value = lst->number;
			bigger.index = i;
		}
		lst = lst->next;
		i++;
	}
	return (bigger);
}
