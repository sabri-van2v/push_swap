/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:38:46 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/05 01:59:35 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_value	advancing_length(t_stack *analyst[2], t_stack **begin_a,
t_stack **begin_b)
{
	t_value	len_tot;
	int		len_a;
	int		len_b;
	int		cost_a;
	int		cost_b;

	cost_a = ft_stack_search_cost(*begin_a, analyst[0]);
	cost_b = ft_stack_search_cost(*begin_b, analyst[1]);
	//ft_printf("cost_a : %d\ncost_b : %d\n", cost_a, cost_b);
	len_a = ft_stack_len(*begin_a);
	len_b = ft_stack_len(*begin_b);
	len_tot.value = cost_a + cost_b;
	len_tot.flag = 0;
	//ft_printf("len_a : %d\nlen_b : %d\nlen_tot : %d\n", len_a, len_b, len_tot.value);
	//exit(0);
	if (cost_a <= len_a / 2 && cost_b <= len_b / 2)
	{
		if (cost_b < cost_a)
			return (len_tot.flag = 1, len_tot.value -= cost_b, len_tot);
		return (len_tot.flag = 1, len_tot.value -= cost_a, len_tot);
	}
	else if (cost_a > len_a / 2 && cost_b > len_b / 2)
	{
		if (cost_b > cost_a)
			return (len_tot.flag = 1, len_tot.value -= len_b - cost_b, len_tot);
		return (len_tot.flag = 1, len_tot.value -= len_a - cost_a, len_tot);
	}
	return (len_tot);
}

t_value	which_place(t_stack *analyst_b, t_stack **begin_a, t_stack **begin_b)
{
	t_stack	*analyst_a;
	t_stack	*analyst_tot[2];
	t_stack	*good;
	t_value	return_value;
	int		i;

	good = good_place(analyst_b, begin_a);
	//printf("good : %d\n", good->number);
	analyst_a = *begin_a;
	i = 1;
	while (analyst_a != good && i <= ft_stack_len(*begin_a) / 2)
	{
		analyst_a = analyst_a->next;
		i++;
	}
	//exit(0);
	analyst_tot[0] = analyst_a;
	analyst_tot[1] = analyst_b;
	return_value = advancing_length(analyst_tot, begin_a, begin_b);
	return_value.index = i;
	return (return_value);
}

t_couple	search_good_number(t_stack **begin_a, t_stack **begin_b)
{
	t_couple	best;
	t_stack		*analyst_b;
	int			i;
	int			stock;

	i = 1;
	best.flag = 0;
	analyst_b = *begin_b;
	best.a_index = 1;
	best.b_index = 1;
	stock = INT32_MAX;
	while (i <= ft_stack_len(*begin_b))
	{
		if (which_place(analyst_b, begin_a, begin_b).value < stock)
		{
			
			//ft_printf("---BEFORE best.a : %d\n---BEFORE best.b : %d\n", best.a_index, best.b_index);
			stock = which_place(analyst_b, begin_a, begin_b).value;
			best.b_index = i;
			best.a_index = which_place(analyst_b, begin_a, begin_b).index;
			//printf("best.a_index : %d\n", best.a_index);
			best.flag = which_place(analyst_b, begin_a, begin_b).flag;
			//printf("couple.index_a : %d\n", best.a_index);
			//printf("couple.index_b : %d\n", best.b_index);
			//ft_printf("---AFTER best.a : %d\n---AFTER best.b : %d\n", best.a_index, best.b_index);
		}
		analyst_b = analyst_b->next;
		i++;
	}
	//ft_printf("---END best.a : %d\n---END best.b : %d\n", best.a_index, best.b_index);
	return (best);
}

void	algorithm(t_stack **begin_a, t_stack **begin_b, t_string *str)
{
	t_couple	couple;

	while (ft_stack_len(*begin_b) > 0)
	{
		couple = search_good_number(begin_a, begin_b);
		
		while (couple.a_index > 1 && couple.b_index > 1 && couple.flag)
			multiple_r(begin_a, begin_b, str, couple.flag);
		if (couple.a_index <= ft_stack_len(*begin_a) / 2
			|| couple.b_index <= ft_stack_len(*begin_b) / 2)
			good_setup_rab(couple, begin_a, begin_b, str);
		else if (couple.a_index > ft_stack_len(*begin_a) / 2
			|| couple.b_index > ft_stack_len(*begin_b) / 2)
			good_setup_rrab(couple, begin_a, begin_b, str);
		p(begin_a, begin_b, str, 'a');
	}
}
