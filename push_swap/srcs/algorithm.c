/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:38:46 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/27 15:18:42 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions_ra(t_stack *begin, t_string *str, t_sb *stack_b, int lower)
{
	
}

void	instructions_rra(t_stack *begin, t_string *str, t_sb *stack_b, int lower)
{
	t_stack	*lst;

	lst = begin->
	while ();
}

void	instructions(t_stack *begin, t_string *str, t_sb *stack_b)
{
	t_lower	lower;
	int		len;
	int		half;

	while (ft_stack_len(begin))
	{
		len = ft_stack_len(begin);
		half = len / 2;
		lower = ft_stack_search_lower(begin);
		if (lower.index < half)
			instructions_ra(begin, str, stack_b, lower);
		else
			instructions_rra(begin, str, stack_b, lower);
		pb(begin, stack_b);
	}
}
