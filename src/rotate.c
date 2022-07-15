/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:19:46 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 05:13:58 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*node;

	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	ft_lstadd_back(stack, node);
}

void	ra(t_list **stack_a)
{
	if (*stack_a == NULL)
		exit_print("ra not possible, empty stack.");
	rotate(stack_a);
	ft_putendl("ra");
}

void	rb(t_list **stack_b)
{
	if (*stack_b == NULL)
		exit_print("rb not possible, empty stack.");
	rotate(stack_b);
	ft_putendl("rb");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL)
		exit_print("rr not possible, empty stack_a.");
	if (*stack_b == NULL)
		exit_print("rr not possible, empty stack_b.");
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl("rr");
}
