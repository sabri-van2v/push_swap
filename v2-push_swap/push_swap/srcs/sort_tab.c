/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:12:04 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 02:12:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	lower_number(int *arr, int max)
{
	int	i;
	int	lower;

	i = 0;
	lower = arr[0];
	while (i < max)
	{
		if (arr[i] < lower)
			lower = arr[i];
		i++;
	}
	return (lower);
}

void	sort_tab(t_tab *tab)
{
	int	i;
	int	index_lower;
	int	lower;

	i = 0;
	index_lower = 0;
	while (i < tab->len)
	{
		lower = lower_number(&tab->array[i], tab->len - i);
		index_lower = 0;
		while (tab->array[index_lower] != lower)
			index_lower++;
		tab_swap(&tab->array[i], &tab->array[index_lower]);
		i++;
	}
}
