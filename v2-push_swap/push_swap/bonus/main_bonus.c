/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:54:59 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/09 02:05:34 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	checker_instructions(t_stack **begin_a, t_stack **begin_b, char *str)
{
	int	return_value;

	return_value = 0;
	if (!str)
		return (0);
	if (ft_strlen(str) == 4)
		return_value = call_rr(begin_a, begin_b, str);
	else if (str[0] == 'r')
		return_value = call_r(begin_a, begin_b, str);
	else if (str[0] == 's')
		return_value = call_s(begin_a, begin_b, str);
	else if (str[0] == 'p')
		return_value = call_p(begin_a, begin_b, str);
	else
		return (1);
	if (return_value == 1)
		return (1);
	if (!*begin_b && !*begin_a)
		return (-1);
	return (0);
}

void	brain(t_stack *begin_a)
{
	char	*str;
	t_stack	*begin_b;
	int		return_value;

	begin_b = NULL;
	str = malloc(1);
	if (!str)
		return ;
	str[0] = '\0';
	while (str != NULL)
	{
		free(str);
		str = get_next_line(0);
		return_value = checker_instructions(&begin_a, &begin_b, str);
		if (return_value < 0)
			return (free(str));
		if (return_value > 0)
			return (write(2, "Error\n", 6), free(str));
	}
	return_value = final_check(begin_a, begin_b);
	if (return_value > 0)
		ft_printf("KO\n");
	else if (return_value == 0)
		ft_printf("OK\n");
	stack_delete(&begin_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*begin_a;
	t_tab	tab;
	int		i;

	if (!stack_error(argc, argv))
		return (0);
	begin_a = NULL;
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
	brain(begin_a);
	stack_delete(&begin_a);
	free(tab.array);
}
