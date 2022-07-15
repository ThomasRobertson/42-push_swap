/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:02:23 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 20:29:59 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	test_functions(t_list **stack_a)
{
	return ;
	sa(stack_a);
	ra(stack_a);
	rra(stack_a);
} */

int	main(int ac, char **av)
{
	t_list			*stack_a;
	unsigned int	size;

	if (ac == 1)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	stack_a = create_chained_list(ac, av);
	size = ft_lstsize(stack_a);
	// test_functions(&stack_a);
	if (size <= 3)
		stack_a = sort_upto_three(&stack_a);
	/* if (is_stacks_sort(stack_a, NULL))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE); */
}
