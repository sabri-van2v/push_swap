/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 05:05:03 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/07 17:31:35 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	order(t_stack **begin_a, t_tab tab)
{
	t_stack	*lower;
	int		len;

	len = stack_len(*begin_a);
	lower = *begin_a;
	while (lower->number != tab.array[0])
		lower = lower->next;
	if (lower->link > len / 2)
	{
		while (lower->link != 1)
			rra(begin_a);
	}
	else
	{
		while (lower->link != 1)
			ra(begin_a);
	}
}
