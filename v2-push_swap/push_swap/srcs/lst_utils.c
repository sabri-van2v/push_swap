/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:03:47 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 02:03:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->number = value;
	lst->link = 1;
	lst->next = NULL;
	return (lst);
}

int	stack_add(t_stack **begin, int value)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (-1);
	lst->number = value;
	lst->next = *begin;
	lst->link = 0;
	*begin = lst;
	stack_incrementation(begin);
	return (0);
}

int	stack_len(t_stack *begin)
{
	int	i;

	i = 0;
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}
