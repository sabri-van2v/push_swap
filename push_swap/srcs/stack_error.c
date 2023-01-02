/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:39:30 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/02 00:28:30 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_number(char *str)
{
	int	i;

	i = 0;
	if ((ft_strlen(str) > 10 && str[0] != '-') || ft_strlen(str) > 11)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_duplicate(char **argv)
{
	int	i;
	int	storage;

	i = 1;
	while (argv[i])
	{
		storage = i;
		i--;
		while (i > 0)
		{
			if (!ft_strcmp_ps(argv[i], argv[storage], 0) || !argv[storage])
				return (0);
			i--;
		}
		i = storage;
		i++;
	}
	return (1);
}

int	check_max_min(char *str)
{
	char	*int_max;
	char	*int_min;

	int_max = "2147483647";
	int_min = "-2147483648";
	if (str[0] == '-' && !ft_strcmp_ps(int_min, str, 1))
		return (0);
	else if (str[0] != '-' && !ft_strcmp_ps(int_max, str, 1))
		return (0);
	return (1);
}

int	stack_error(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i])
	{
		if (!validate_number(argv[i]))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	i = 1;
	while (argv[i])
	{
		if (!check_max_min(argv[i]))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	if (!check_duplicate(argv))
		return (write(2, "Error\n", 6), 0);
	return (1);
}
