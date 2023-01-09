/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 07:06:37 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/07 18:04:06 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **begin_a, t_stack **begin_b)
{
	int	value;
	int	return_value;

	value = (*begin_b)->number;
	delete_element(begin_b);
	return_value = stack_add(begin_a, value);
	if (return_value < 0)
		return (stack_delete(begin_a), stack_delete(begin_b));
	write(1, "pa\n", 3);
}

void	pb(t_stack **begin_a, t_stack **begin_b)
{
	int	value;
	int	return_value;

	value = (*begin_a)->number;
	delete_element(begin_a);
	return_value = stack_add(begin_b, value);
	if (return_value < 0)
		return (stack_delete(begin_a), stack_delete(begin_b));
	write(1, "pb\n", 3);
}
