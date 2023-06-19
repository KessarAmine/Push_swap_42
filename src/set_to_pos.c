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

#include "push_swap.h"

// if i am at bottom half i reverse rotate and the cost goes up untill  0
// one of stack a or B element
// is in position = becomes 0,
// the stack has been rotated as far as possible and the top position is correct
static void	rrr_both(t_stack **a, t_stack **b, int *cost_pos_a, int *cost_top_b)
{
	while (*cost_pos_a < 0 && *cost_top_b < 0)
	{
		(*cost_pos_a)++;
		(*cost_top_b)++;
		rrr(a, b);
	}
}

static void	rr_both(t_stack **a, t_stack **b, int *cost_pos_a, int *cost_top_b)
{
	while (*cost_pos_a > 0 && *cost_top_b > 0)
	{
		(*cost_pos_a)--;
		(*cost_top_b)--;
		rr(a, b);
	}
}

static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

// put them both on the correct position until cost_pos_a and 
// cost_top_b gets to 0
// to optimize it we check if both of them are in bottom or top 
// part to apply the same thing on them
// and then if one of them is not yet at position 0 we just make 
// individuallyy go there and apply pa
// this is more effficient then making em seperatly,
// we went from 667 steps to 635 steps on same input
void	set_to_pos(t_stack **a, t_stack **b, int cost_pos_a, int cost_top_b)
{
	if (cost_pos_a < 0 && cost_top_b < 0)
		rrr_both(a, b, &cost_pos_a, &cost_top_b);
	else if (cost_pos_a > 0 && cost_top_b > 0)
		rr_both(a, b, &cost_pos_a, &cost_top_b);
	rotate_a(a, &cost_pos_a);
	rotate_b(b, &cost_top_b);
	pa(a, b);
}
