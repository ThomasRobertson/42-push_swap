/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_chained_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:56:37 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 17:08:18 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	nbr_occurence_bigger(t_list *stack, int value)
{
	unsigned int	nbr;

	nbr = 0;
	while (stack)
	{
		if (stack->content->value > value)
			nbr++;
		stack = stack->next;
	}
	return (nbr);
}

void	get_index(t_list *stack_a)
{
	size_t			size;
	unsigned int	occurence;
	t_list			*first_node;

	first_node = stack_a;
	size = ft_lstsize(stack_a);
	while (stack_a)
	{
		occurence = nbr_occurence_bigger(first_node, stack_a->content->value);
		stack_a->content->index = size - occurence;
		stack_a = stack_a->next;
	}
}
