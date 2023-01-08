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

#include "push_swap_bonus.h"

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
	*begin = tmp;
}

void	rra(t_stack **begin_a)
{
	reverse_rotate_action(begin_a);
}

void	rrb(t_stack **begin_b)
{
	reverse_rotate_action(begin_b);
}

void	rrr(t_stack **begin_a, t_stack **begin_b)
{
	reverse_rotate_action(begin_a);
	reverse_rotate_action(begin_b);
}

void	call_rr(t_stack **begin_a, t_stack **begin_b, char *str)
{
	if (!ft_strncmp(str, "rra\n", 4))
		rra(begin_a, begin_b);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(begin_a, begin_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(begin_a, begin_b);
}
