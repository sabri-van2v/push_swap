/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:40:37 by svan-de-          #+#    #+#             */
/*   Updated: 2023/01/07 21:39:07 by svan-de-         ###   ########.fr       */
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
	int				link;
}	t_stack;

typedef struct s_tab
{
	int	*array;
	int	len;
}	t_tab;

typedef struct s_short
{
	int		index_a;
	char	sens_a;
	int		index_b;
	char	sens_b;
	int		len_tot;
}	t_short;

void	sa(t_stack **begin_a);

void	sb(t_stack **begin_b);

void	rotate_action(t_stack **begin);

void	ra(t_stack **begin_a);

void	rb(t_stack **begin_b);

void	rr(t_stack **begin_a, t_stack **begin_b);

void	reverse_rotate_action(t_stack **begin);

void	rra(t_stack **begin_a);

void	rrb(t_stack **begin_b);

void	rrr(t_stack **begin_a, t_stack **begin_b);

void	pa(t_stack **begin_a, t_stack **begin_b);

void	pb(t_stack **begin_a, t_stack **begin_b);

t_stack	*stack_new(int value);

int		stack_add(t_stack **begin, int value);

int		stack_len(t_stack *begin);

void	stack_incrementation(t_stack **begin);

void	stack_decrementation(t_stack **begin);

int		ft_strcmp_ps(char *s1, char *s2, int flag);

void	order(t_stack **begin_a, t_tab tab);

void	stack_delete(t_stack **begin);

void	delete_element(t_stack **begin);

int		next_number_index(t_stack *begin_a);

int		len_same(int index_a, int index_b, int len_a, int len_b);

int		len_opposite(int index_a, int index_b, int len_a, int len_b);

t_short	calcul_path(t_stack *begin_a, t_stack *begin_b);

t_short	short_path(t_stack *begin_a, t_stack *begin_b);

void	opposite_sens(t_stack **begin_a, t_stack **begin_b, t_short path);

void	ascending(t_stack **begin_a, t_stack **begin_b, t_short path);

void	down(t_stack **begin_a, t_stack **begin_b, t_short path);

int		sorting_algorithm(t_stack **begin_a, t_stack **begin_b);

int		power(int nb, int power);

int		good_median(t_tab tab);

void	pb_optimisation(t_stack **begin_a, t_stack **begin_b);

void	create_b(t_stack **begin_a, t_stack **begin_b);

t_stack	*presorting(t_stack **begin_a, t_tab tab);

int		bigger_index(t_stack **begin_a);

void	len_3(t_stack **begin_a);

void	len_2(t_stack **begin_a);

void	little_len(t_stack **begin_a, int len);

void	tab_swap(int *a, int *b);

int		lower_number(int *arr, int max);

void	sort_tab(t_tab *tab);

int		stack_add_for_a(t_stack **begin_a, int value);

t_stack	*create_stack_a(t_tab tab);

int		validate_number(char *str);

int		check_duplicate(char **argv);

int		check_max_min(char *str);

int		stack_error(int argc, char *argv[]);

void	brain(t_stack *begin_a, t_tab tab);

int		main(int argc, char *argv[]);

void	print_stack(t_stack *begin);

void	print_tab(t_tab tab);

void	print_short(t_short	path);

#endif
