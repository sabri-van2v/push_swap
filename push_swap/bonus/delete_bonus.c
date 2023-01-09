/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:26:20 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 03:26:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	stack_delete(t_stack **begin)
{
	while (*begin)
		delete_element(begin);
}

void	delete_element(t_stack **begin)
{
	t_stack	*tmp;

	tmp = *begin;
	*begin = (*begin)->next;
	free(tmp);
}
