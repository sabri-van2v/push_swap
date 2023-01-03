/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:40:37 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/03 16:46:25 by svan-de-         ###   ########.fr       */
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

typedef struct s_value
{
	int	index;
	int	value;
}	t_value;

typedef struct s_couple
{
	t_value	a;
	t_value	b;
	int		fl;
}	t_couple;

typedef struct s_string
{
	int		index;
	char	*str_malloc;
}	t_string;

void		rab(t_stack **begin, t_string *str, char flag);

void		rrab(t_stack **begin, t_string *str, char flag);

void		multiple_r(t_stack **begin_a, t_stack **begin_b,
				t_string *str, int f);

void		p(t_stack **receive, t_stack **send, t_string *str, char flag);

void		s(t_stack **begin, t_string *str, char flag);

void		full_rotate(t_stack **begin_a, t_string *str);

int			advancing_length(t_stack *analyst[2], t_couple *take_the_best,
				t_stack **begin_a, t_stack **begin_b);

t_couple	search_good_number(t_stack **begin_a, t_stack **begin_b);

void		algorithm(t_stack **begin_a, t_stack **begin_b, t_string *str);

int			good_median(t_stack *list, int len);

int			median_calculation(t_stack *begin);

void		creation_b(t_stack **begin_a, t_stack **begin_b, int b_create);

void		push_presorting(t_stack **begin_a, t_stack **begin_b,
				t_string *str);

void		presorting(t_stack **begin_a, t_stack **begin_b, t_string *str);

void		len_3(t_stack **begin_a, t_string *str);

void		len_2(t_stack **begin_a, t_string *str);

void		little_len(t_stack **begin_a, t_string *str, int len);

t_value		ft_stack_search_lower(t_stack *begin_a);

t_value		ft_stack_search_bigger(t_stack *begin_a);

t_stack		*ft_stack_new(int first_int, int second_int);

void		ft_stack_add(t_stack **begin, int new_number);

int			ft_stack_len(t_stack *begin);

int			ft_stack_search_cost(t_stack *begin, t_stack *lst);

void		ft_stack_delete(t_stack **begin);

int			ft_strlen_arr_str(char **arr_str);

void		ft_putstr_one_call(char *str);

int			ft_strcmp_ps(char *s1, char *s2, int flag);

int			validate_number(char *str);

int			check_duplicate(char **argv);

int			check_max_min(char *str);

int			stack_error(int argc, char *argv[]);

char		*sorting_algorithm(t_stack *begin_a);

t_stack		*create_stack(int len, int *number);

int			main(int argc, char *argv[]);

#endif
