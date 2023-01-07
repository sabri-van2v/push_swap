/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:22:46 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/07 17:42:08 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *begin)
{
	printf("-----START_STACK-----\n");
	while (begin)
	{
		printf("%d\n", begin->number);
		begin = begin->next;
	}
	printf("------END_STACK------\n");
}

void	print_tab(t_tab tab)
{
	int	i;

	i = 0;
	printf("-----START_TAB-----\n");
	printf("len = %d\n", tab.len);
	while (i < tab.len)
		printf("%d\n", tab.array[i++]);
	printf("------END_TAB------\n");
}
