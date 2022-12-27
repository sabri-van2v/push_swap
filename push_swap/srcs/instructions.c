/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 07:06:37 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/27 10:59:03 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *begin, t_sb *stack_b, t_string *str)
{
	begin = begin->next;
	str->str_malloc[str->index] = 'r';
	str->index++;
	str->str_malloc[str->index] = 'a';
	str->index++;
	str->str_malloc[str->index] = '\n';
	str->index++;
}

void	rra(t_stack *begin, t_sb *stack_b, t_string *str)
{
	begin = begin->last;
	str->str_malloc[str->index] = 'r';
	str->index++;
	str->str_malloc[str->index] = 'r';
	str->index++;
	str->str_malloc[str->index] = 'a';
	str->index++;
	str->str_malloc[str->index] = '\n';
	str->index++;
}

void	pa(t_stack *begin, t_sb *stack_b, t_string *str)
{
	ft_stack_add(begin, stack_b.array[stack_b->index]);
	index--;
	ft_stack_delete(begin);
	str->str_malloc[str->index] = 'p';
	str->index++;
	str->str_malloc[str->index] = 'a';
	str->index++;
	str->str_malloc[str->index] = '\n';
	str->index++;
}

void	pb(t_stack *begin, t_sb *stack_b, t_string *str)
{
	stack_b.array[stack_b->index] = begin->number;
	stack_b->index++;
	ft_stack_delete(begin);
	str->str_malloc[str->index] = 'p';
	str->index++;
	str->str_malloc[str->index] = 'b';
	str->index++;
	str->str_malloc[str->index] = '\n';
	str->index++;
}
