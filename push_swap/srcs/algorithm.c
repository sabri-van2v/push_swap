/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:38:46 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/03 23:00:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	full_rotate(t_stack **begin_a, t_string *str)
{
	t_value	lower;
	t_value	bigger;
	int		sense;

	lower = ft_stack_search_lower(*begin_a);
	bigger = ft_stack_search_bigger(*begin_a);
	if (lower.index < ft_stack_len(*begin_a))
		sense = 1;
	else
		sense = 0;
	while ((*begin_a)->number != lower.value
		&& (*begin_a)->last->number != bigger.value)
	{
		if (sense == 1)
			rab(begin_a, str, 'a');
		else
			rrab(begin_a, str, 'a');
	}
}

int	advancing_length(t_stack *analyst[2], t_couple *take_the_best,
t_stack **begin_a, t_stack **begin_b)
{
	int	len_tot;
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	cost_a = ft_stack_search_cost(*begin_a, analyst[0]);
	cost_b = ft_stack_search_cost(*begin_b, analyst[1]);
	len_a = ft_stack_len(*begin_a);
	len_b = ft_stack_len(*begin_b);
	len_tot = cost_a + cost_b;
	if (cost_a <= len_a / 2 && cost_b <= len_b / 2 && take_the_best->fl++)
	{
		if (cost_b < cost_a)
			return (len_tot -= cost_b);
		return (len_tot -= cost_a);
	}
	else if (cost_a > len_a / 2 && cost_b > len_b / 2 && take_the_best->fl++)
	{
		if (cost_b > cost_a)
			return (len_tot -= len_b - cost_b);
		len_tot -= len_a - cost_a;
	}
	ft_printf("len_tot : %d\n", len_tot);
	return (len_tot);
}

t_couple	search_good_number(t_stack **begin_a, t_stack **begin_b)
{
	t_couple	take_the_best;
	t_stack		*analyst[2];
	int			i;
	int			j;
	int			stock;

	j = 1;
	i = 1;
	take_the_best.fl = 0;
	analyst[0] = *begin_a;
	analyst[1] = *begin_b;
	stock = INT32_MAX;
	while (i < ft_stack_len(*begin_b))
	{
		if (advancing_length(analyst, &take_the_best, begin_a, begin_b) < stock)
		{
			stock = advancing_length(analyst, &take_the_best, begin_a, begin_b);
			take_the_best.a.index = j;
			take_the_best.b.index = i;
		}
		j++;
		analyst[0] = analyst[0]->next;
		if (analyst[0] == *begin_a)
		{
			analyst[1] = analyst[1]->next;
			i++;
			j = 0;
		}
	}
	return (take_the_best);
}

void	algorithm(t_stack **begin_a, t_stack **begin_b, t_string *str)
{
	t_couple	couple;

	while (ft_stack_len(*begin_b) > 0)
	{
		couple = search_good_number(begin_a, begin_b);
		// ft_printf("couple.a.index : %d\n", couple.a.index);
		// ft_printf("couple.b.index : %d\n", couple.b.index);
		while (couple.a.index > 1 && couple.b.index > 1 && couple.fl)
			multiple_r(begin_a, begin_b, str, couple.fl);
		while (couple.a.index > 1 || couple.b.index > 1)
		{
			if (couple.a.index < ft_stack_len(*begin_a) / 2 && couple.a.index > 1)
				rab(begin_a, str, 'a');
			if (couple.a.index > ft_stack_len(*begin_a) / 2)
				rrab(begin_a, str, 'a');
			if (couple.b.index < ft_stack_len(*begin_b) / 2 && couple.b.index > 1)
				rab(begin_a, str, 'b');
			if (couple.b.index > ft_stack_len(*begin_b) / 2)
				rrab(begin_a, str, 'b');
		}
		p(begin_a, begin_b, str, 'a');
	}
}
