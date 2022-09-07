/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:36:01 by troberts          #+#    #+#             */
/*   Updated: 2022/09/07 20:25:34 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_moves_was_too_long(char *move)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free(move);
	exit(EXIT_FAILURE);
}

static void	do_moves(t_list **stack_a, t_list **stack_b, char *move)
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
		do_moves_was_too_long(move);
}

static void	get_moves(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		do_moves(stack_a, stack_b, line);
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	stack_a = create_chained_list(ac, av);
	stack_b = NULL;
	get_moves(&stack_a, &stack_b);
	if (is_stacks_sort(stack_a, stack_b))
	{
		ft_putstr_fd("OK\n", STDOUT_FILENO);
		ft_lstclear(&stack_a, free);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("KO\n", STDOUT_FILENO);
		ft_lstclear(&stack_a, free);
		ft_lstclear(&stack_b, free);
		return (EXIT_FAILURE);
	}
}
