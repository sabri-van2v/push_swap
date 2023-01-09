/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:22:46 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/09 03:27:02 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_stack(t_stack *begin)
{
	printf("-----START_STACK-----\n");
	while (begin)
	{
		printf("%d -- %d\n", begin->number, begin->link);
		begin = begin->next;
	}
	printf("------END_STACK------\n");
}

void	print_tab(t_tab tab)
{
	int	i;

	i = 0;
	printf("-----START_TAB-----\n");
	if (tab)
	{
		printf("len = %d\n", tab.len);
		while (i < tab.len)
			printf("%d\n", tab.array[i++]);
	}
	printf("------END_TAB------\n");
}
