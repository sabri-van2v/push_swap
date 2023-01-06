/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incrementation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:44:43 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 03:44:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_incrementation(t_stack **begin)
{
    t_stack *browse;

    browse = *begin;
    while (browse)
    {
        browse->link++;
        browse = browse->next;
    }
}

void    stack_decrementation(t_stack **begin)
{
    t_stack *browse;

    browse = *begin;
    while (browse)
    {
        browse->link--;
        browse = browse->next;
    }
}
