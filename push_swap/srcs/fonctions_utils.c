/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 05:05:03 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/04 17:56:52 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_arr_str(char **arr_str)
{
	int	i;

	i = 1;
	if (!arr_str)
		return (0);
	while (arr_str[i])
		i++;
	return (i - 1);
}

void	ft_putstr_one_call(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

int	ft_strcmp_ps(char *s1, char *s2, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		if (ft_strlen(s1) < ft_strlen(s2))
			return (0);
		if (ft_strlen(s1) > ft_strlen(s2))
			return (1);
		while (s1[i])
		{
			if (s1[i] < s2[i])
				return (0);
			if (s1[i] > s2[i])
				return (1);
			i++;
		}
		return (1);
	}
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	full_rotate(t_stack **begin_a, t_string *str)
{
	t_value	lower;
	t_value	bigger;
	int		sense;

	lower = ft_stack_search_lower(*begin_a);
	bigger = ft_stack_search_bigger(*begin_a);
	if (lower.index < ft_stack_len(*begin_a))
		sense = 1;
	else
		sense = 0;
	while ((*begin_a)->number != lower.value
		&& (*begin_a)->last->number != bigger.value)
	{
		if (sense == 1)
			rab(begin_a, str, 'a');
		else
			rrab(begin_a, str, 'a');
	}
}
