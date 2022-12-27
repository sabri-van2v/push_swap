/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 05:05:03 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/27 02:04:35 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_arr_str(char **arr_str)
{
	int	i;

	i = 1;
	if (!arr_str)
		return (0);
	while (arr_str[i])
		i++;
	return (i - 1);
}

void	ft_putstr_one_call(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

int	ft_strcmp_ps(char *s1, char *s2, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		if (ft_strlen(s1) < ft_strlen(s2))
			return (0);
		if (ft_strlen(s1) > ft_strlen(s2))
			return (1);
		while (s1[i])
		{
			if (s1[i] < s2[i])
				return (0);
			if (s1[i] > s2[i])
				return (1);
			i++;
		}
		return (1);
	}
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
