/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:39:37 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 04:25:29 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node->next->next != NULL)
		node = node->next;
	ft_lstadd_front(stack, node->next);
	node->next = NULL;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl("rra");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl("rrb");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl("rrr");
}
