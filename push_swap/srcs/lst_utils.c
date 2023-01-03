/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:51:44 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/03 15:50:17 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int first_int, int second_int)
{
	t_stack	*lst1;
	t_stack	*lst2;

	lst1 = malloc(sizeof(t_stack));
	lst2 = malloc(sizeof(t_stack));
	if (!lst1 || !lst2)
		return (free(lst1), free(lst2), NULL);
	lst1->number = first_int;
	lst2->number = second_int;
	lst1->next = lst2;
	lst1->last = lst2;
	lst2->next = lst1;
	lst2->last = lst1;
	return (lst1);
}

void	ft_stack_add(t_stack **begin, int new_number)
{
	t_stack	*new_stack;
	t_stack	*last;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return ((void)free(*begin));
	last = (*begin)->next;
	while (last->next != *begin)
		last = last->next;
	new_stack->number = new_number;
	new_stack->last = last;
	new_stack->next = *begin;
	(*begin)->last = new_stack;
	last->next = new_stack;
}

int	ft_stack_len(t_stack *begin)
{
	int		i;
	t_stack	*lst;

	i = 1;
	if (begin == NULL)
		return (0);
	lst = begin->next;
	while (lst != begin)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_stack_search_cost(t_stack *begin, t_stack *lst)
{
	int		index_1;
	int		index_2;
	t_stack	*search;

	index_1 = 0;
	index_2 = 0;
	search = begin;
	while (1)
	{
		if (search == lst)
			break ;
		search = search->next;
		index_1++;
	}
	search = begin;
	while (1)
	{
		if (search == lst)
			break ;
		search = search->next;
		index_2++;
	}
	if (index_1 < index_2)
		return (index_1);
	return (index_2);
}

void	ft_stack_delete(t_stack **begin)
{
	t_stack	*tmp;

	tmp = *begin;
	if ((*begin)->number == (*begin)->next->number)
	{
		free(*begin);
		*begin = NULL;
		return ;
	}
	*begin = (*begin)->next;
	(*begin)->last = tmp->last;
	tmp->last->next = *begin;
	free(tmp);
}
