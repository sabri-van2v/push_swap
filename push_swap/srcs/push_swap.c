/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:40:27 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/02 02:08:11 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sorting_algorithm(t_stack *begin_a)
{
	t_stack		begin_b;
	t_string	str;
	int			len;

	str.index = 0;
	str.str_malloc = malloc(sizeof(char) * 22000);
	if (!str.str_malloc)
		return (str.str_malloc, NULL);
	len = ft_stack_len(begin_a);
	if (len > 1 && len < 4)
		return (little_len(&begin_a, &str, len), str.str_malloc);
	presorting(&begin_a, &str, &begin_b);
	algorithm(&begin_a, &str, &begin_b);
	full_rotate(&begin_a, &str);
	str.str_malloc[str.index] = '\0';
	return (str.str_malloc);
}

t_stack	*create_stack(int len, int *number)
{
	t_stack	*begin_a;
	int		i;

	i = 2;
	begin_a = ft_stack_new(number[0], number[1]);
	if (!begin_a)
		return (NULL);
	while (i < len && begin_a)
		ft_stack_add(&begin_a, ft_atoi(number[i]));
	return (begin_a);
}

int	main(int argc, char *argv[])
{
	t_stack	*begin_a;
	char	*str;
	int		*tab;
	int		i;

	i = 1;
	if (!stack_error(argc, argv))
		return (0);
	tab = malloc(sizeof(int) * ft_strlen_arr_str(argv + 1));
	if (!tab)
		return (0);
	while (argv[i])
		tab[i - 1] = argv[i++];
	begin_a = create_stack(i - 1, tab);
	if (!begin_a)
		return (0);
	str = sorting_algorithm(begin_a);
	ft_putstr_one_call(str);
}
