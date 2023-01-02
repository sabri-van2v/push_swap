/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:38:46 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/02 05:14:16 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	advancing_length(t_stack *an_a, t_stack *an_b, t_couple goo, t_couple sea)
{
	int	len_a;
	int	len_b;

	
}

t_couple	search_good_number(t_stack **begin_a, t_stack **begin_b)
{
	t_couple	search;
	t_couple	good;
	t_stack		*analyst_a;
	t_stack		*analyst_b;
	int			i;

	i = 0;
	good.same_way = 0;
	search.same_way = 0;
	analyst_a = begin_a;
	analyst_b = begin_b;
	while (i < ft_stack_len(begin_b))
	{
		if (advancing_length(analyst_a, analyst_b, &good, &search) < )
			good = search;
		analyst_a = analyst_a->next;
		if (analyst_a == begin_a)
		{
			analyst_b = analyst_b->next;
			i++;
		}
	}
	return (good);
}

void	algorithm(t_stack **begin_a, t_stack **begin_b, t_string *str)
{
	t_couple	couple;

	while (ft_stack_len(*begin_b) > 0)
	{
		couple = search_good_number(begin_a, begin_b);
		while (couple.a.index > 1 && couple.b.index > 1 && couple.same_way)
			multiple_r(begin_a, begin_b, str, couple.same_way);
		while (couple.a.index > 1 || couple.b.index > 1)
		{
			if (couple.a.index < ft_stack_len(begin_a) / 2)
				rab(begin_a, str, 'a');
			if (couple.a.index > ft_stack_len(begin_a) / 2)
				rrab(begin_a, str, 'a');
			if (couple.b.index < ft_stack_len(begin_b) / 2)
				rab(begin_a, str, 'b');
			if (couple.b.index > ft_stack_len(begin_b) / 2)
				rrab(begin_a, str, 'b');
		}
		p(begin_a, begin_b, str, 'a');
	}
}
