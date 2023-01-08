/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 05:05:03 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/08 22:57:11 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	final_check(t_stack *begin_a, t_stack *begin_b)
{
	int	check;

	if (begin_b)
		return (1);
	check = begin_a->number;
	begin_a = begin_a->next;
	while (begin_a)
	{
		if (check > begin_a->number)
			return (1);
		check = begin_a->number;
		begin_a = begin_a->next;
	}
	return (0);
}
