/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 07:06:37 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/03 15:50:06 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rab(t_stack **begin, t_string *str, char flag)
{
	*begin = (*begin)->next;
	str->str_malloc[str->index++] = 'r';
	if (flag == 'a')
		str->str_malloc[str->index++] = 'a';
	else if (flag == 'b')
		str->str_malloc[str->index++] = 'b';
	str->str_malloc[str->index++] = '\n';
}

void	rrab(t_stack **begin, t_string *str, char flag)
{
	*begin = (*begin)->last;
	str->str_malloc[str->index++] = 'r';
	str->str_malloc[str->index++] = 'r';
	if (flag == 'a')
		str->str_malloc[str->index++] = 'a';
	else if (flag == 'b')
		str->str_malloc[str->index++] = 'b';
	str->str_malloc[str->index++] = '\n';
}

void	multiple_r(t_stack **begin_a, t_stack **begin_b, t_string *str, int f)
{
	if (f == 1)
	{
		*begin_a = (*begin_a)->next;
		*begin_b = (*begin_b)->next;
		str->str_malloc[str->index++] = 'r';
		str->str_malloc[str->index++] = 'r';
		str->str_malloc[str->index++] = '\n';
	}
	if (f == 2)
	{
		*begin_a = (*begin_a)->last;
		*begin_b = (*begin_b)->last;
		str->str_malloc[str->index++] = 'r';
		str->str_malloc[str->index++] = 'r';
		str->str_malloc[str->index++] = 'r';
		str->str_malloc[str->index++] = '\n';
	}
}

void	p(t_stack **receive, t_stack **send, t_string *str, char flag)
{
	ft_stack_add(receive, (*send)->number);
	*receive = (*receive)->last;
	ft_stack_delete(send);
	str->str_malloc[str->index++] = 'p';
	if (flag == 'a')
		str->str_malloc[str->index++] = 'a';
	else if (flag == 'b')
		str->str_malloc[str->index++] = 'b';
	str->str_malloc[str->index++] = '\n';
}

void	s(t_stack **begin, t_string *str, char flag)
{
	int	tmp;

	tmp = (*begin)->number;
	(*begin)->number = (*begin)->next->number;
	(*begin)->next->number = tmp;
	str->str_malloc[str->index++] = 's';
	if (flag == 'a')
		str->str_malloc[str->index++] = 'a';
	else if (flag == 'b')
		str->str_malloc[str->index++] = 'b';
	str->str_malloc[str->index++] = '\n';
}
