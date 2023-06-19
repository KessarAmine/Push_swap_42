/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:44:46 by kmohamed          #+#    #+#             */
/*   Updated: 2023/04/11 13:24:09 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	norme_fixe(int *i, long int *nb)
{
	(*nb) = 0;
	(*i) = 1;
}

t_stack	*init_stack_a(int arg_count, char **arg_values)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;
	int			j;
	char		**split;

	stack_a = NULL;
	norme_fixe(&i, &nb);
	while (i < arg_count)
	{
		j = 0;
		split = ft_split(arg_values[i], ' ');
		if (!split[j])
			return (0);
		while (split[j])
		{
			nb = ft_atoi(split[j++]);
			if (nb > INT_MAX || nb < INT_MIN)
				throw_error(&stack_a, NULL);
			add_node(&stack_a, new_node((int)nb));
		}
		free_split(split);
		i++;
	}
	return (stack_a);
}

void	index_stack(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
