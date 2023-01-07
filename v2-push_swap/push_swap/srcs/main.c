/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:40:27 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/07 18:28:30 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brain(t_stack *begin_a, t_tab tab)
{
	t_stack	*begin_b;
	int		return_value;

	if (tab.len == 2 || tab.len == 3)
		little_len(&begin_a, tab.len);
	begin_b = presorting(&begin_a, tab);
	if (!begin_b)
		return (stack_delete(&begin_a));
	return_value = sorting_algorithm(&begin_a, &begin_b);
	if (return_value < 0)
		return (stack_delete(&begin_a), stack_delete(&begin_b));
	order(&begin_a, tab);
	stack_delete(&begin_a);
}

int	main(int argc, char *argv[])
{
	t_stack	*begin_a;
	t_tab	tab;
	int		i;

	if (!stack_error(argc, argv))
		return (0);
	i = 1;
	tab.len = argc - 1;
	tab.array = malloc(sizeof(int) * (argc - 1));
	if (!tab.array)
		return (0);
	while (argv[i])
	{
		tab.array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	begin_a = create_stack_a(tab);
	if (!begin_a)
		return (free(tab.array), 0);
	sort_tab(&tab);
	brain(begin_a, tab);
	free(tab.array);
}
