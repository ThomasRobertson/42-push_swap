/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:15:25 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 09:03:14 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_two(t_list **stack_a)
{
	if (is_stacks_sort(*stack_a, NULL))
		return (*stack_a);
	sa(stack_a);
	return (*stack_a);
}

t_list	*sort_three(t_list **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	while (is_stacks_sort(*stack_a, NULL) == false)
	{
		first = (*stack_a)->content;
		second = (*stack_a)->next->content;
		third = (*stack_a)->next->next->content;
		if (first->index > second->index && first->index > third->index)
			ra(stack_a);
		else if (second->index > first->index && second->index > third->index)
			rra(stack_a);
		else if (first->index > second->index)
			sa(stack_a);
		else
			exit_print("Couldn't sort three numbers.");
	}
	return (*stack_a);
}

t_list	*sort_upto_three(t_list **stack_a)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		return (*stack_a);
	if (size == 2)
		return (sort_two(stack_a));
	if (size == 3)
		return (sort_three(stack_a));
	return (NULL);
}
