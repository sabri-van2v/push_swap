/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:40:37 by svan-de-          #+#    #+#             */
/*   Updated: 2022/12/29 20:27:44 by svan-de-         ###   ########.fr       */
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

void	ra(t_stack *begin, t_string *str);

void	rra(t_stack *begin, t_string *str);

void	pa(t_stack *begin, t_sb *stack_b, t_string *str);

void	pb(t_stack *begin, t_sb *stack_b, t_string *str);

void	instructions_ra(t_stack *begin, t_string *str);

void	instructions_rra(t_stack *begin, t_string *str);

void	instructions(t_stack *begin, t_string *str, t_sb *stack_b);

t_lower	ft_stack_search_bigger(t_stack *begin);

void	len_3(t_stack *begin, t_string *str);

void	len_2(t_stack *begin, t_string *str);

void	little_len(t_stack *begin, t_string *str, int len);

t_stack	*ft_stack_new(int new_int);

void	ft_stack_add(t_stack *begin, int new_number);

int		ft_stack_len(t_stack *begin);

t_lower	ft_stack_search_lower(t_stack *begin);

void	ft_stack_delete(t_stack *begin);

int		ft_strlen_arr_str(char **arr_str);

int		ft_check_r_or_s(char *last_str, char *new_str, int *i, int *j);

char	*ft_check_double_instruction(char *last_str);

void	ft_putstr_one_call(char *str);

int		ft_strcmp_ps(char *s1, char *s2, int flag);

int		validate_number(char *str);

int		check_duplicate(char **argv);

int		check_max_min(char *str);

int		stack_error(int argc, char **argv, int f);

char	*sorting_algorithm(t_stack *begin);

t_stack	*create_stack(int len, char **numbers);

int		main(int argc, char *argv[]);

#endif