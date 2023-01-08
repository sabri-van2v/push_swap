/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:22:46 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/07 21:31:57 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("len = %d\n", tab.len);
	while (i < tab.len)
		printf("%d\n", tab.array[i++]);
	printf("------END_TAB------\n");
}

void	print_short(t_short path)
{
	printf("----START_SHORT----\n");
	printf("path.index_a : %d\n", path.index_a);
	printf("path.sens_a : %c\n", path.sens_a);
	printf("path.index_b : %d\n", path.index_b);
	printf("path.sens_b : %c\n", path.sens_b);
	printf("path.len_tot : %d\n", path.len_tot);
	printf("-----END_SHORT-----\n");
}
