/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:58:42 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/03 22:30:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_median(t_stack *list, int len)
{
	int		lower;
	int		upper;
	t_stack	*checker;

	lower = 0;
	upper = 0;
	checker = list;
	while (lower <= len / 2 && upper <= len / 2 && checker->next != list)
	{
		if (checker->number <= list->number)
			lower++;
		if (checker->number > list->number)
			upper++;
		checker = checker->next;
	}
	if (lower == upper || lower == upper - 1 || lower == upper + 1)
		return (1);
	return (0);
}

int	median_calculation(t_stack *begin)
{
	int		len;
	int		index;

	len = ft_stack_len(begin);
	index = 0;
	while (index < len)
	{
		if (good_median(begin, len))
			return (begin->number);
		index++;
		begin = begin->next;
	}
	return (0);
}

void	creation_b(t_stack **begin_a, t_stack **begin_b, t_string *str, int b_create)
{
	if (b_create == 0)
		(*begin_b)->next->number = (*begin_a)->number;
	else if (b_create == 1)
		(*begin_b)->number = (*begin_a)->number;
	ft_stack_delete(begin_a);
	str->str_malloc[str->index++] = 'p';
	str->str_malloc[str->index++] = 'b';
	str->str_malloc[str->index++] = '\n';
}

void	push_presorting(t_stack **begin_a, t_stack **begin_b, t_string *str)
{
	if ((*begin_a)->number < (*begin_b)->last->number)
		rrab(begin_b, str, 'b');
	p(begin_b, begin_a, str, 'b');
	if ((*begin_b)->number < (*begin_b)->next->number)
		s(begin_b, str, 'b');
}

void	presorting(t_stack **begin_a, t_stack **begin_b, t_string *str)
{
	int	median;
	int	len;
	int	index;
	int	b_create;

	b_create = 0;
	*begin_b = ft_stack_new(0, 0);
	while (ft_stack_len(*begin_a) > 3)
	{
		median = median_calculation(*begin_a);
		len = ft_stack_len(*begin_a);
		index = 0;
		while (index < len / 2)
		{
			// ft_printf("median : %d\n", median);
			// ft_printf("begin_a->number : %d\n", (*begin_a)->number);
			// ft_printf("begin_a->last : %d\n", (*begin_a)->last->number);
			if ((*begin_a)->number <= median && b_create != 2)
				creation_b(begin_a, begin_b, str, b_create++);
			else if ((*begin_a)->number <= median && b_create == 2)
				push_presorting(begin_a, begin_b, str);
			else if ((*begin_a)->number > median)
				rab(begin_a, str, 'a');
			index++;
		}
	}
	little_len(begin_a, str, 3);
}
