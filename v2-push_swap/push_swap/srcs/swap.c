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

#include "push_swap.h"

void	sa(t_stack **begin_a)
{
	int	tmp;

	tmp = (*begin_a)->number;
	(*begin_a)->number = (*begin_a)->next->number;
	(*begin_a)->next->number = tmp;
    write(1, "sa\n", 3);
}

void	sb(t_stack **begin_b)
{
	int	tmp;
    int tmp_index;

	tmp = (*begin_b)->number;
    tmp_index = (begin_b)->link;
	(*begin_b)->number = (*begin_b)->next->number;
	(*begin_b)->next->number = tmp;
    write(1, "sb\n", 3);
}
