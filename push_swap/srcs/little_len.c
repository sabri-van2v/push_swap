/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:00:53 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/01 19:43:10 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lower	ft_stack_search_bigger(t_stack *begin_a)
{
	t_stack	*lst;
	int		i;
	t_lower	bigger;

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

void	len_3(t_stack **begin_a, t_string *str)
{
	t_stack	*tmp;
	t_lower	bigger;

	tmp = *begin_a;
	bigger = ft_stack_search_bigger(*begin_a);
	if (bigger.index == 1)
		ra(begin_a, str);
	else if (bigger.index == 2)
		rra(begin_a, str);
	len_2(begin_a, str);
}

void	len_2(t_stack **begin_a, t_string *str)
{
	if ((*begin_a)->number > (*begin_a)->next->number)
	{
		ft_strlcpy(&str->str_malloc[str->index], "sa\n", 4);
		str->index += 3;
	}
}

void	little_len(t_stack **begin_a, t_string *str, int len)
{
	if (len == 2)
		return (len_2(begin_a, str));
	if (len == 3)
		return (len_3(begin_a, str));
}
