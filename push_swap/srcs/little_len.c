/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:00:53 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/30 19:21:17 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lower	ft_stack_search_bigger(t_stack *begin)
{
	t_stack	*lst;
	int		i;
	t_lower	bigger;

	i = 2;
	bigger.value = begin->number;
	bigger.index = 1;
	lst = begin->next;
	while (lst != begin)
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

void	len_3(t_stack **begin, t_string *str)
{
	t_stack	*tmp;
	t_lower	bigger;

	tmp = *begin;
	bigger = ft_stack_search_bigger(*begin);
	if (bigger.index == 1)
		ra(begin, str);
	else if (bigger.index == 2)
		rra(begin, str);
	len_2(begin, str);
}

void	len_2(t_stack **begin, t_string *str)
{
	if ((*begin)->number > (*begin)->next->number)
	{
		ft_strlcpy(&str->str_malloc[str->index], "sa\n", 4);
		str->index += 3;
	}
}

void	little_len(t_stack **begin, t_string *str, int len)
{
	if (len == 2)
		return (len_2(begin, str));
	if (len == 3)
		return (len_3(begin, str));
}
