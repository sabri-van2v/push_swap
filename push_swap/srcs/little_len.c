/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:00:53 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/04 22:18:23 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	len_3(t_stack **begin_a, t_string *str)
{
	t_value	bigger;

	bigger = ft_stack_search_bigger(*begin_a);
	if (bigger.index == 1)
		rab(begin_a, str, 'a');
	else if (bigger.index == 2)
		rrab(begin_a, str, 'a');
	len_2(begin_a, str);
}

void	len_2(t_stack **begin_a, t_string *str)
{
	if ((*begin_a)->number > (*begin_a)->next->number)
	{
		ft_strlcpy(&str->str_malloc[str->index], "sa\n", 4);
		str->index += 3;
	}
}

void	little_len(t_stack **begin_a, t_string *str, int len)
{
	if (len == 2)
		return (len_2(begin_a, str));
	if (len == 3)
		return (len_3(begin_a, str));
}
