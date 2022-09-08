/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:36:01 by troberts          #+#    #+#             */
/*   Updated: 2022/09/07 23:01:34 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	do_moves(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		sa(stack_a, true);
	else if (ft_strcmp(move, "sb\n") == 0)
		sb(stack_b, true);
	else if (ft_strcmp(move, "ss\n") == 0)
		ss(stack_a, stack_b, true);
	else if (ft_strcmp(move, "pa\n") == 0)
		pa(stack_a, stack_b, true);
	else if (ft_strcmp(move, "pb\n") == 0)
		pb(stack_a, stack_b, true);
	else if (ft_strcmp(move, "ra\n") == 0)
		ra(stack_a, true);
	else if (ft_strcmp(move, "rb\n") == 0)
		rb(stack_b, true);
	else if (ft_strcmp(move, "rr\n") == 0)
		rr(stack_a, stack_b, true);
	else if (ft_strcmp(move, "rra\n") == 0)
		rra(stack_a, true);
	else if (ft_strcmp(move, "rrb\n") == 0)
		rrb(stack_b, true);
	else if (ft_strcmp(move, "rrr\n") == 0)
		rrr(stack_a, stack_b, true);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	get_moves(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (do_moves(stack_a, stack_b, line) == EXIT_FAILURE)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	stack_a = create_chained_list(ac, av);
	stack_b = NULL;
	if (get_moves(&stack_a, &stack_b) == EXIT_SUCCESS)
	{
		if (is_stacks_sort(stack_a, stack_b))
		{
			ft_putstr_fd("OK\n", STDOUT_FILENO);
			ft_lstclear(&stack_a, free);
			return (EXIT_SUCCESS);
		}
		else
			ft_putstr_fd("KO\n", STDOUT_FILENO);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (EXIT_FAILURE);
}
