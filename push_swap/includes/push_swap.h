/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:40:37 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/27 11:42:27 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*last;
}	t_stack;

typedef struct s_lower
{
	int	index;
	int	value;
}	t_lower;

typedef struct s_string
{
	int		index;
	char	*str_malloc;
}	t_string;

typedef struct s_stack_b
{
	int		index;
	int		*array;
}	t_sb;

void	ft_stack_add(t_stack *begin, int new_number);

t_stack	*ft_stack_new(int new);

int		ft_strcmp_ps(char *s1, char *s2, int flag);

int		validate_number(char *str);

int		check_duplicate(char **argv);

int		check_max_min(char *str);

int		stack_error(int argc, char **argv);

int		ft_strlen_arr_str(char **arr_str);

void	ft_putstr_one_call(char *str);

#endif