/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 07:06:37 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/08 23:10:26 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack **begin_a, t_stack **begin_b)
{
	int	value;
	int	return_value;

	value = (*begin_b)->number;
	delete_element(begin_b);
	return_value = stack_add(begin_a, value);
	if (return_value < 0)
		return (stack_delete(begin_a), stack_delete(begin_b));
}

void	pb(t_stack **begin_a, t_stack **begin_b)
{
	int	value;
	int	return_value;

	return_value = 0;
	value = (*begin_a)->number;
	delete_element(begin_a);
	if (!*begin_b)
	{
		*begin_b = stack_new(value);
		if (!*begin_b)
			return (stack_delete(begin_a));
	}
	else
		return_value = stack_add(begin_b, value);
	if (return_value < 0)
		return (stack_delete(begin_a), stack_delete(begin_b));
}

void	call_p(t_stack **begin_a, t_stack **begin_b, char *str)
{
	if (!ft_strncmp(str, "pa\n", 3))
		pa(begin_a, begin_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(begin_a, begin_b);
}
