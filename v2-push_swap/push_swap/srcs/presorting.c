/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:58:42 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/08 21:29:18 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	power(int nb, int power)
{
	int	i;
	int	valeurstock;

	valeurstock = nb;
	i = 1;
	while (i < power)
	{
		nb *= valeurstock;
		i++;
	}
	return (nb);
}

int	good_median(t_tab tab)
{
	static int	call = 1;
	int			good_index;

	good_index = tab.len - (tab.len / power(2, call));
	call++;
	return (good_index);
}

void	pb_optimisation(t_stack **begin_a, t_stack **begin_b)
{
	t_stack	*last;

	pb(begin_a, begin_b);
	if (!*begin_a || !*begin_b)
		return ;
	last = *begin_b;
	while (last->next)
		last = last->next;
	if ((*begin_b)->number < last->number && stack_len(*begin_b) > 2)
		rb(begin_b);
	if ((*begin_b)->number < (*begin_b)->next->number)
		sb(begin_b);
}

void	create_b(t_stack **begin_a, t_stack **begin_b)
{
	static int	flag = 0;

	*begin_b = stack_new((*begin_a)->number);
	delete_element(begin_a);
	if (!*begin_b || flag == 1)
		return ;
	write(1, "pb\n", 3);
	flag++;
}

t_stack	*presorting(t_stack **begin_a, t_tab tab)
{
	int		len;
	int		median;
	int		index_median;
	t_stack	*begin_b;

	begin_b = NULL;
	while (stack_len(*begin_a) > 3)
	{
		index_median = good_median(tab);
		median = tab.array[index_median];
		len = stack_len(*begin_a);
		while (len > 0 && stack_len(*begin_a) > 3)
		{
			if ((*begin_a)->number > median)
				ra(begin_a);
			else if (!begin_b && (*begin_a)->number <= median)
				create_b(begin_a, &begin_b);
			else if ((*begin_a)->number <= median)
				pb_optimisation(begin_a, &begin_b);
			len--;
		}
	}
	little_len(begin_a, 3);
	return (begin_b);
}
