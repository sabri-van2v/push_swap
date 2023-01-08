/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:23:32 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 00:23:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack **begin_a)
{
	int	tmp;

	tmp = (*begin_a)->number;
	(*begin_a)->number = (*begin_a)->next->number;
	(*begin_a)->next->number = tmp;
}

void	sb(t_stack **begin_b)
{
	int	tmp;

	tmp = (*begin_b)->number;
	(*begin_b)->number = (*begin_b)->next->number;
	(*begin_b)->next->number = tmp;
}

void	call_s(t_stack **begin_a, t_stack **begin_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(begin_a, begin_b);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(begin_a, begin_b);
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		sa(begin_a);
		sb(begin_b);
	}
}
