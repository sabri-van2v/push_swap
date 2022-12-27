/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:40:27 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/27 11:39:32 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sorting_algorithm(t_stack *begin)
{
	t_sb		stack_b;
	t_string	str;
	int			len;

	stack_b.array = malloc(sizeof(int) * ft_stack_len(begin));
	str.str_malloc = malloc(sizeof(char) * 22000);
	if (!str.str_malloc || !stack_b.array)
		return (free(begin), free(stack_b.array), free(stack_b.array), NULL);
	str.index = 0;
	stack_b.index = 0;
	len = ft_stack_len(begin);
	if (len > 1 && len < 6)
		return (little_len(begin, &str));
	instructions(begin, &str, &stack_b);
	while (stack_b.index > 0)
		pa(begin, &stack_b, &str);
	return (str.str_malloc);
}

t_stack	*create_stack(int len, char **numbers)
{
	t_stack	*begin;
	int		i;

	i = 1;
	begin = ft_stack_new(ft_atoi(numbers[0]));
	if (!begin)
		return (NULL);
	while (i < len && begin)
		ft_stack_add(begin, ft_atoi(numbers[i++]));
	return (begin);
}

int	main(int argc, char *argv[])
{
	t_stack	*begin;

	if (!stack_error(argc, argv))
		return (0);
	begin = create_stack(argc - 1, (argv + 1));
	if (!begin)
		return (0);
	str = sorting_algorithm(begin);
	str = "yes\n";
	ft_putstr_one_call(str);

	t_stack	*lst;
	lst = begin;
	ft_printf("%d\n", lst->number);
	lst = lst->next;
	while (lst != begin)
	{
		ft_printf("%d\n", lst->number);
		lst = lst->next;
	}
	free(begin);
}
