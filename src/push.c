/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:59:01 by troberts          #+#    #+#             */
/*   Updated: 2022/07/12 10:54:55 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*node;

	if (*stack_from == NULL)
		return ;
	node = *stack_from;
	*stack_from = (*stack_from)->next;
	ft_lstadd_front(stack_to, node);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl("pa");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl("pb");
}
