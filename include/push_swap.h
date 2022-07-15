/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:58:26 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 20:36:41 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>

# include "list_struct.h"
# include "libft.h"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

t_list	*create_chained_list(int ac, char **av);
t_bool	check_args(int ac, char **av, int **array_int, unsigned int *size);

char	**get_array(int ac, char **av);
int		*convert_array_to_int(char **array);
char	**get_array_single_arg(char *av);
char	**get_array_multiple_args(int ac, char **av);

void	get_index(t_list *stack_a);

void	ss(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
t_list	*sort_upto_three(t_list **stack_a);
t_bool	is_stacks_sort(t_list *stack_a, t_list *stack_b);

void	free_double_ptr_char(char **arr_char);
void	exit_print(char *str);

#endif