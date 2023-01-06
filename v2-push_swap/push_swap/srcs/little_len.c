/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:00:53 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/06 01:25:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_index(t_stack **begin_a)
{
	int		bigger_index;
	int		bigger_value;
	t_stack	*search;

	bigger_index = 1;
	bigger_value = (*begin_a)->number;
	search = *begin_a;
	while (search)
	{
		if (search->number > bigger_value)
		{
			bigger_index = search->link;
			bigger_value = search->numer;
		}
		search = search->next;
	}
	return (bigger_index);
}

void	len_3(t_stack **begin_a)
{
	int	bigger;

	bigger = bigger_index(begin_a);
	if (bigger.index == 1)
		ra(begin_a);
	else if (bigger.index == 2)
		rra(begin_a);
	len_2(begin_a);
}

void	len_2(t_stack **begin_a)
{
	if ((*begin_a)->number > (*begin_a)->next->number)
		sa(begin_a);
}

void	little_len(t_stack **begin_a, int len)
{
	if (len == 2)
		return (len_2(begin_a));
	if (len == 3)
		return (len_3(begin_a));
}
