/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:38:46 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/30 23:18:18 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions_ra(t_stack **begin, t_string *str)
{
	t_lower	lower;

	lower = ft_stack_search_lower(begin);
	while (lower.index > 1)
	{
		ra(begin, str);
		lower = ft_stack_search_lower(begin);
	}
}

void	instructions_rra(t_stack **begin, t_string *str)
{
	t_lower	lower;

	lower = ft_stack_search_lower(begin);
	while (lower.index > 1)
	{
		rra(begin, str);
		lower = ft_stack_search_lower(begin);
	}
}

void	instructions(t_stack **begin, t_string *str, t_sb *stack_b)
{
	t_lower	lower;
	int		half;

	while (ft_stack_len(*begin) > 1)
	{
		half = ft_stack_len(*begin) / 2;
		lower = ft_stack_search_lower(begin);
		if (lower.index < half)
			instructions_ra(begin, str);
		else
			instructions_rra(begin, str);
		pb(begin, stack_b, str);
	}
}
