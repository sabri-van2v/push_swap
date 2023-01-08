/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 04:41:58 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 04:41:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opposite_sens(t_stack **begin_a, t_stack **begin_b, t_short path)
{
	if (path.sens_a == 'a')
	{
		while (path.index_a != 1 && path.index_a--)
			ra(begin_a);
		while (path.index_b != 1 && path.index_b <= stack_len(*begin_b)
			&& path.index_b++)
			rrb(begin_b);
	}
	else
	{
		while (path.index_a != 1 && path.index_a <= stack_len(*begin_a)
			&& path.index_a++)
			rra(begin_a);
		while (path.index_b != 1 && path.index_b--)
			rb(begin_b);
	}
}

void	ascending(t_stack **begin_a, t_stack **begin_b, t_short path)
{
	while (path.index_a != 1 && path.index_b != 1)
	{
		rr(begin_a, begin_b);
		path.index_a--;
		path.index_b--;
	}
	while (path.index_a != 1 && path.index_a--)
		ra(begin_a);
	while (path.index_b != 1 && path.index_b--)
		rb(begin_b);
}

void	down(t_stack **begin_a, t_stack **begin_b, t_short path)
{
	while (path.index_a != 1 && path.index_a <= stack_len(*begin_a)
		&& path.index_b != 1 && path.index_b <= stack_len(*begin_b))
	{
		rrr(begin_a, begin_b);
		path.index_a++;
		path.index_b++;
	}
	while (path.index_a != 1 && path.index_a <= stack_len(*begin_a)
		&& path.index_a++)
		rra(begin_a);
	while (path.index_b != 1 && path.index_b <= stack_len(*begin_b)
		&& path.index_b++)
		rrb(begin_b);
}

int	sorting_algorithm(t_stack **begin_a, t_stack **begin_b)
{
	t_short	path;

	while (stack_len(*begin_b))
	{
		path = short_path(*begin_a, *begin_b);
		if (path.sens_a == 'a' && path.sens_b == 'a')
			ascending(begin_a, begin_b, path);
		else if (path.sens_a == 'd' && path.sens_b == 'd')
			down(begin_a, begin_b, path);
		else
			opposite_sens(begin_a, begin_b, path);
		pa(begin_a, begin_b);
		if (!*begin_a)
			return (-1);
	}
	return (0);
}
