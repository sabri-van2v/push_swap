/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:40:27 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/30 23:17:23 by svan-de-         ###   ########.fr       */
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
		return (free(stack_b.array), free(stack_b.array), NULL);
	str.index = 0;
	stack_b.index = 0;
	len = ft_stack_len(begin);
	if (len > 1 && len < 4)
		return (little_len(&begin, &str, len), str.str_malloc);
	instructions(&begin, &str, &stack_b);
	while (stack_b.index > 0)
		pa(&begin, &stack_b, &str);
	str.str_malloc[str.index] = '\0';
	return (str.str_malloc);
}

t_stack	*create_stack(int len, char **numbers)
{
	t_stack	*begin;
	int		i;

	i = 2;
	begin = ft_stack_new(ft_atoi(numbers[0]), ft_atoi(numbers[1]));
	if (!begin)
		return (NULL);
	while (i < len && begin)
		ft_stack_add(&begin, ft_atoi(numbers[i++]));
	return (begin);
}

int	main(int argc, char *argv[])
{
	t_stack	*begin;
	char	*str;
	char	**split;
	int		len_split;

	len_split = 0;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		len_split = ft_strlen_arr_str(split);
		if (!stack_error(len_split, split, 1))
			return (0);
		begin = create_stack(len_split + 1, split);
	}
	else
	{
		if (!stack_error(argc, argv, 0))
			return (0);
		begin = create_stack(argc - 1, (argv + 1));
	}
	if (!begin)
		return (0);
	str = sorting_algorithm(begin);
	ft_putstr_one_call(str);
}
