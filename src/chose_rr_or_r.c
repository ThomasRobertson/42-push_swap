/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_rr_or_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:07:04 by troberts          #+#    #+#             */
/*   Updated: 2022/07/27 02:46:17 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_lower_and_b_lower(t_list **stack_a, t_list **stack_b, \
	long int *cost_a, long int *cost_b)
{
	rrr(stack_a, stack_b, false);
	(*cost_a)++;
	(*cost_b)++;
}

static void	a_higher_and_b_higher(t_list **stack_a, t_list **stack_b, \
	long int *cost_a, long int *cost_b)
{
	rr(stack_a, stack_b, false);
	(*cost_a)--;
	(*cost_b)--;
}

static void	cost_a_function(t_list **stack_a, long int *cost_a)
{
	if ((*cost_a) < 0)
	{
		rra(stack_a, false);
		(*cost_a)++;
	}
	else if ((*cost_a) > 0)
	{
		ra(stack_a, false);
		(*cost_a)--;
	}	
}

void	chose_and_do_rr_or_r(t_list **stack_a, t_list **stack_b, \
	long int cost_a, long int cost_b)
{
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_a < 0 && cost_b < 0)
			a_lower_and_b_lower(stack_a, stack_b, &cost_a, &cost_b);
		else if (cost_a > 0 && cost_b > 0)
			a_higher_and_b_higher(stack_a, stack_b, &cost_a, &cost_b);
		else if (cost_a != 0)
			cost_a_function(stack_a, &cost_a);
		else if (cost_b < 0)
		{
			rrb(stack_b, false);
			cost_b++;
		}
		else if (cost_b > 0)
		{
			rb(stack_b, false);
			cost_b--;
		}
	}
}
