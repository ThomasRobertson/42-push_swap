/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:20:43 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 07:24:11 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*node;
	t_list	*third_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	node = *stack;
	third_node = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = node;
	(*stack)->next->next = third_node;
	return ;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl("sa");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putendl("sb");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl("ss");
}
