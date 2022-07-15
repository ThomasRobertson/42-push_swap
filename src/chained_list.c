/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:08:34 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 20:37:00 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*create_node(int value)
{
	t_stack	*node;
	t_list	*list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		exit(EXIT_FAILURE);
	node = malloc(sizeof(*node));
	if (node == NULL)
		exit(EXIT_FAILURE);
	node->value = value;
	node->cost_a = -1;
	node->cost_b = -1;
	node->index = -1;
	node->pos = -1;
	node->target_pos = -1;
	list->content = node;
	list->next = NULL;
	return (list);
}

t_list	*create_chained_list(int ac, char **av)
{
	unsigned int	i;
	t_list			*node;
	t_list			*stack_a;
	int				*array;
	unsigned int	size;

	check_args(ac, av, &array, &size);
	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		node = create_node(array[i++]);
		if (node == NULL)
		{
			ft_lstclear(&stack_a, free);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, node);
	}
	get_index(stack_a);
	free(array);
	return (stack_a);
}
