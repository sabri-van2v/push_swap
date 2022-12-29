/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:51:44 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/29 16:58:18 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int new_int)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->number = new_int;
	lst->last = NULL;
	lst->next = NULL;
	return (lst);
}

void	ft_stack_add(t_stack *begin, int new_number)
{
	t_stack	*new_stack;
	t_stack	*last;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return ((void)free(begin));
	last = begin;
	while (last->next && last->next != begin)
		last = last->next;
	new_stack->number = new_number;
	new_stack->last = last;
	new_stack->next = begin;
	last->next = new_stack;
}

int	ft_stack_len(t_stack *begin)
{
	int		i;
	t_stack	*lst;

	if (!begin || (begin && !begin->next && !begin->last))
		return (0);
	i = 1;
	lst = begin->next;
	while (lst != begin)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_lower	ft_stack_search_lower(t_stack *begin)
{
	t_stack	*lst;
	int		i;
	t_lower	lower;

	i = 2;
	lower.value = begin->number;
	lower.index = 1;
	lst = begin->next;
	while (lst != begin)
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

void	ft_stack_delete(t_stack *begin)
{
	t_stack	*tmp;

	tmp = begin;
	begin = begin->next;
	begin->last = tmp->last;
	tmp->last->next = begin;
	free(tmp);
}
