/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:29:11 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 00:29:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_action(t_stack **begin)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *begin;
	last = *begin;
	while (last->next)
		last = last->next;
	(*begin) = (*begin)->next;
	tmp->next = NULL;
	tmp->link = last->link + 1;
	last->next = tmp;
	stack_decrementation(begin);
}

void	ra(t_stack **begin_a)
{
	rotate_action(begin_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **begin_b)
{
	rotate_action(begin_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **begin_a, t_stack **begin_b)
{
	rotate_action(begin_a);
	rotate_action(begin_b);
	write(1, "rr\n", 3);
}
