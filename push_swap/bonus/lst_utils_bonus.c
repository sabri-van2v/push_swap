/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:03:55 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/08 23:07:15 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*stack_new(int value)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->number = value;
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
	*begin = lst;
	return (0);
}
