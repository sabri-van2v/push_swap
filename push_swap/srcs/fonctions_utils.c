/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 05:05:03 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/31 17:29:07 by svan-de-         ###   ########.fr       */
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

int	ft_check_r_or_s(char *last_str, char *new_str, int *i, int *j)
{
	if (last_str[*i] == 's')
	{
		if (!ft_strncmp(&last_str[*i], "sa\nsb\n", 6))
			return (ft_strlcpy(&new_str[*j], "ss\n", 3), *i += 6, *j += 3, 0);
		else if (!ft_strncmp(&last_str[*i], "sb\nsa\n", 6))
			return (ft_strlcpy(&new_str[*j], "ss\n", 3), *i += 6, *j += 3, 0);
		else
			return (new_str[*j] = last_str[*i], (*i)++, (*j)++);
	}
	else if (last_str[*i] == 'r')
	{
		if (!ft_strncmp(&last_str[*i], "ra\nrb\n", 6))
			return (ft_strlcpy(&new_str[*j], "rr\n", 3), *i += 6, *j += 3, 0);
		else if (!ft_strncmp(&last_str[*i], "rb\nra\n", 6))
			return (ft_strlcpy(&new_str[*j], "rr\n", 3), *i += 6, *j += 3, 0);
		else if (!ft_strncmp(&last_str[*i], "rra\nrrb\n", 8))
			return (ft_strlcpy(&new_str[*j], "rrr\n", 3), *i += 6, *j += 3, 0);
		else if (!ft_strncmp(&last_str[*i], "rrb\nrra\n", 8))
			return (ft_strlcpy(&new_str[*j], "rrr\n", 3), *i += 6, *j += 3, 0);
		else
			return (new_str[*j] = last_str[*i], (*i)++, (*j)++);
	}
	else
		return (new_str[*j] = last_str[*i], (*i)++, (*j)++);
	return (0);
}

char	*ft_check_double_instruction(char *last_str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	ft_printf("%s\n", last_str);
	new_str = malloc(sizeof(char) * ft_strlen(last_str));
	if (!new_str)
		return (last_str);
	while (last_str[i])
	{
		if (i == 0 || last_str[i] == 'r' || last_str[i] == 's')
			ft_check_r_or_s(last_str, new_str, &i, &j);
		else
		{
			new_str[j] = last_str[i];
			i++;
			j++;
		}
	}
	free (last_str);
	return (new_str);
}

void	ft_putstr_one_call(char *str)
{
	int	len;

	// str = ft_check_double_instruction(str);
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
