/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:55:42 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/09 03:52:08 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_tab
{
	int	*array;
	int	len;
}	t_tab;

void	pa(t_stack **begin_a, t_stack **begin_b);

void	pb(t_stack **begin_a, t_stack **begin_b);

int		call_p(t_stack **begin_a, t_stack **begin_b, char *str);

void	reverse_rotate_action(t_stack **begin);

void	rra(t_stack **begin_a);

void	rrb(t_stack **begin_b);

void	rrr(t_stack **begin_a, t_stack **begin_b);

int		call_rr(t_stack **begin_a, t_stack **begin_b, char *str);

void	rotate_action(t_stack **begin);

void	ra(t_stack **begin_a);

void	rb(t_stack **begin_b);

void	rr(t_stack **begin_a, t_stack **begin_b);

int		call_r(t_stack **begin_a, t_stack **begin_b, char *str);

void	sa(t_stack **begin_a);

void	sb(t_stack **begin_b);

int		call_s(t_stack **begin_a, t_stack **begin_b, char *str);

t_stack	*stack_new(int value);

int		stack_add(t_stack **begin, int value);

int		stack_add_for_a(t_stack **begin_a, int value);

t_stack	*create_stack_a(t_tab tab);

void	stack_delete(t_stack **begin);

void	delete_element(t_stack **begin);

int		ft_strcmp_ps(char *s1, char *s2, int flag);

int		final_check(t_stack *begin_a, t_stack *begin_b);

int		validate_number(char *str);

int		check_duplicate(char **argv);

int		check_max_min(char *str);

int		stack_error(int argc, char *argv[]);

int		checker_instructions(t_stack **begin_a, t_stack **begin_b, char *str);

void	brain(t_stack **begin_a);

int		main(int argc, char *argv[]);

#endif
