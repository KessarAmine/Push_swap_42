/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:45:36 by kmohamed          #+#    #+#             */
/*   Updated: 2023/04/11 13:35:34 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_pos_a;
	int				cost_top_b;
	struct s_stack	*next;
}	t_stack;

t_stack		*init_stack_a(int arg_count, char **arg_values);
void		index_stack(t_stack *stack_a, int ac);

int			is_sorted(t_stack *stack);
void		sort_3(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

void		get_cost_b_to_a(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

void		set_to_pos(t_stack **a, t_stack **b, int ca, int cost_top_b);

void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);

t_stack		*get_list_tail(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*new_node(int value);
void		add_node(t_stack **stack, t_stack *new);
int			get_list_size(t_stack	*stack);

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);

void		throw_error(t_stack **stack_a, t_stack **stack_b);

int			is_correct_input(char **av, int argc);
char		**ft_split(char const *s, char c);
void		free_split(char **split);
int			is_digit(char c);
int			compare(const char *s1, const char *s2);
int			norme_fixe1(char **split, int *s_inc);
int			have_duplicates(char **av);
int			is_sign(char s);
int			is_number(char *av);
#endif