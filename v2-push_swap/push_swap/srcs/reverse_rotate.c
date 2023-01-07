/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:27:07 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 00:27:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_action(t_stack **begin)
{
	t_stack	*tmp;
	t_stack	*before_last;

	tmp = *begin;
	before_last = *begin;
	while (tmp->next)
		tmp = tmp->next;
	while (before_last->next != tmp)
		before_last = before_last->next;
	before_last->next = NULL;
	tmp->next = (*begin);
	tmp->link = 0;
	*begin = tmp;
	stack_incrementation(begin);
}

void	rra(t_stack **begin_a)
{
	reverse_rotate_action(begin_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **begin_b)
{
	reverse_rotate_action(begin_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **begin_a, t_stack **begin_b)
{
	reverse_rotate_action(begin_a);
	reverse_rotate_action(begin_b);
	write(1, "rrr\n", 4);
}
