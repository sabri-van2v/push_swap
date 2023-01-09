/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 04:16:10 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 04:16:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_add_for_a(t_stack **begin_a, int value)
{
	t_stack	*lst;
	t_stack	*last;

	last = *begin_a;
	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (-1);
	while (last->next)
		last = last->next;
	lst->number = value;
	lst->next = NULL;
	last->next = lst;
	return (0);
}

t_stack	*create_stack_a(t_tab tab)
{
	t_stack	*begin_a;
	int		return_value;
	int		i;

	i = 1;
	begin_a = stack_new(tab.array[0]);
	if (!begin_a)
		return (NULL);
	while (i < tab.len)
	{
		return_value = stack_add_for_a(&begin_a, tab.array[i++]);
		if (return_value < 0)
			return (stack_delete(&begin_a), NULL);
	}
	return (begin_a);
}
