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

	if (!*begin_a || !(*begin_a)->next)
		return ;
	tmp = (*begin_a)->number;
	(*begin_a)->number = (*begin_a)->next->number;
	(*begin_a)->next->number = tmp;
}

void	sb(t_stack **begin_b)
{
	int	tmp;

	if (!*begin_b || !(*begin_b)->next)
		return ;
	tmp = (*begin_b)->number;
	(*begin_b)->number = (*begin_b)->next->number;
	(*begin_b)->next->number = tmp;
}

int	call_s(t_stack **begin_a, t_stack **begin_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(begin_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(begin_b);
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		sa(begin_a);
		sb(begin_b);
	}
	else
		return (1);
	return (0);
}
