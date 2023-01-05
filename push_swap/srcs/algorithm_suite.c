/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:40:00 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/05 01:53:34 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*good_place(t_stack *analyst_b, t_stack **begin_a)
{
	t_stack	*checker;
	t_stack	*good;

	checker = *begin_a;
	while (analyst_b->number > checker->number)
		checker = checker->next;
	good = checker;
	checker = (*begin_a)->next;
	while (checker != *begin_a)
	{
		if (analyst_b->number < checker->number
			&& checker->number < good->number)
			good = checker;
		checker = checker->next;
	}
	return (good);
}

void	good_setup_rrab(t_couple couple, t_stack **begin_a, t_stack **begin_b,
t_string *str)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(*begin_a);
	len_b = ft_stack_len(*begin_b);
	//printf("rrab couple.index_a : %d\n", couple.a_index);
	//printf("rrab couple.index_b : %d\n", couple.b_index);
	while (couple.a_index < len_a && couple.a_index > 1 && couple.a_index++)
		rrab(begin_a, str, 'a');
	while (couple.b_index < len_b && couple.b_index > 1 && couple.b_index++)
		rrab(begin_a, str, 'b');
}

void	good_setup_rab(t_couple couple, t_stack **begin_a, t_stack **begin_b,
t_string *str)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(*begin_a);
	len_b = ft_stack_len(*begin_b);
	//printf("rab couple.index_a : %d\n", couple.a_index);
	//printf("rab couple.index_b : %d\n", couple.b_index);
	while (couple.a_index > 1 && couple.a_index--)
		rab(begin_a, str, 'a');
	while (couple.b_index > 1 && couple.b_index--)
		rab(begin_a, str, 'b');
}
