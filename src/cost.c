/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:13:55 by kmohamed          #+#    #+#             */
/*   Updated: 2023/04/11 13:35:56 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	cost_pos_a represents the cost of getting
//  to the right position in stack A
void	get_cost_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_list_size(tmp_a);
	size_b = get_list_size(tmp_b);
	while (tmp_b)
	{
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_top_b = (size_b - tmp_b->pos) * -1;
		else
			tmp_b->cost_top_b = tmp_b->pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_pos_a = (size_a - tmp_b->target_pos) * -1;
		else
			tmp_b->cost_pos_a = tmp_b->target_pos;
		tmp_b = tmp_b->next;
	}
}

static int	nb_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	is_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

// finds the element in stack B with the cheapest cost to move to stack A
// and moves it to the correct position in stack A
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_pos_a;
	int		cost_top_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_pos_a)
			+ nb_abs(tmp->cost_top_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_top_b) + nb_abs(tmp->cost_pos_a);
			cost_pos_a = tmp->cost_pos_a;
			cost_top_b = tmp->cost_top_b;
		}
		tmp = tmp->next;
	}
	set_to_pos(stack_a, stack_b, cost_pos_a, cost_top_b);
}

int	is_correct_input(char **av, int argc)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		if (!split[j])
			return (0);
		while (split[j])
		{
			if (!is_number(split[j++]))
			{
				free_split(split);
				throw_error(NULL, NULL);
			}
		}
		free_split(split);
		i++;
	}
	if (have_duplicates(av))
		return (0);
	return (1);
}
