/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:51:50 by troberts          #+#    #+#             */
/*   Updated: 2022/07/28 16:22:07 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_pos_if_higher_index(t_list *stack_a, t_list *stack_b, \
	unsigned int min_index)
{
	while (stack_a)
	{
		if (stack_a->content->index < min_index)
		{
			min_index = stack_a->content->index;
			stack_b->content->target_pos = stack_a->content->pos;
		}
		stack_a = stack_a->next;
	}
}

static unsigned int	target_pos_was_too_long(t_list *stack_a, t_list *stack_b)
{
	unsigned int	difference;

	difference = stack_a->content->index - stack_b->content->index;
	stack_b->content->target_pos = stack_a->content->pos;
	return (difference);
}

void	get_target_position_stack(t_list *stack_a, t_list *stack_b)
{
	t_list			*first_node_a;
	unsigned int	difference;
	unsigned int	max_index;

	first_node_a = stack_a;
	max_index = 0;
	while (stack_b)
	{
		stack_a = first_node_a;
		difference = UINT_MAX;
		while (stack_a)
		{
			if (stack_a->content->index > max_index)
				max_index = stack_a->content->index;
			if (difference > stack_a->content->index - stack_b->content->index \
				&& stack_a->content->index > stack_b->content->index)
				difference = target_pos_was_too_long(stack_a, stack_b);
			stack_a = stack_a->next;
		}
		if (stack_b->content->index > max_index)
			target_pos_if_higher_index(first_node_a, stack_b, max_index);
		stack_b = stack_b->next;
	}
}

void	get_position_stack(t_list *stack_a, t_list *stack_b)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = (unsigned int)ft_lstsize(stack_a);
	while (i < size)
	{
		stack_a->content->pos = i;
		stack_a = stack_a->next;
		i++;
	}
	if (stack_b)
		get_position_stack(stack_b, NULL);
}

void	get_cost_stack(t_list *stack_a, t_list *stack_b)
{
	size_t	pos_max_b;
	size_t	max_a;

	pos_max_b = ft_lstsize(stack_b);
	max_a = ft_lstsize(stack_a);
	while (stack_b)
	{
		if (pos_max_b - stack_b->content->pos < stack_b->content->pos)
		{
			stack_b->content->cost_b = pos_max_b - stack_b->content->pos;
			stack_b->content->cost_b = -stack_b->content->cost_b;
		}	
		else
			stack_b->content->cost_b = stack_b->content->pos;
		if (max_a - stack_b->content->target_pos < stack_b->content->target_pos)
		{
			stack_b->content->cost_a = max_a - stack_b->content->target_pos;
			stack_b->content->cost_a = -stack_b->content->cost_a;
		}	
		else
			stack_b->content->cost_a = stack_b->content->target_pos;
		stack_b = stack_b->next;
	}
}
