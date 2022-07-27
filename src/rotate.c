/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:19:46 by troberts          #+#    #+#             */
/*   Updated: 2022/07/27 02:56:07 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*node;

	if (*stack == NULL || stack == NULL)
		return ;
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	ft_lstadd_back(stack, node);
}

void	ra(t_list **stack_a, t_bool silent)
{
	rotate(stack_a);
	if (!silent)
		ft_putendl("ra");
}

void	rb(t_list **stack_b, t_bool silent)
{
	rotate(stack_b);
	if (!silent)
		ft_putendl("rb");
}

void	rr(t_list **stack_a, t_list **stack_b, t_bool silent)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!silent)
		ft_putendl("rr");
}
