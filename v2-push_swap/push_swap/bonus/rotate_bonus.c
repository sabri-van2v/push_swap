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

#include "push_swap_bonus.h"

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
	last->next = tmp;
}

void	ra(t_stack **begin_a)
{
	rotate_action(begin_a);
}

void	rb(t_stack **begin_b)
{
	rotate_action(begin_b);
}

void	rr(t_stack **begin_a, t_stack **begin_b)
{
	rotate_action(begin_a);
	rotate_action(begin_b);
}

void	call_r(t_stack **begin_a, t_stack **begin_b, char *str)
{
	if (!ft_strncmp(str, "ra\n", 3))
		ra(begin_a, begin_b);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(begin_a, begin_b);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(begin_a, begin_b);
}
