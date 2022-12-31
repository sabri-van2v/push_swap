/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:51:44 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/30 23:17:52 by svan-de-         ###   ########.fr       */
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

t_lower	ft_stack_search_lower(t_stack **begin)
{
	t_stack	*lst;
	int		i;
	t_lower	lower;

	i = 2;
	lower.value = (*begin)->number;
	lower.index = 1;
	lst = (*begin)->next;
	while (lst != *begin)
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

void	ft_stack_delete(t_stack **begin)
{
	t_stack	*tmp;

	tmp = *begin;
	if ((*begin)->number == (*begin)->next->number)
	{
		free(*begin);
		*begin = NULL;
		ft_printf("JE SUIS LAA\n");
		
		ft_printf("JE SUI PLUS LAA\n");
		return ;
	}
	*begin = (*begin)->next;
	(*begin)->last = tmp->last;
	tmp->last->next = *begin;
	free(tmp);
}
