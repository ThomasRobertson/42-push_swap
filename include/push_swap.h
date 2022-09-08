/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:58:26 by troberts          #+#    #+#             */
/*   Updated: 2022/09/08 19:41:33 by troberts         ###   ########.fr       */
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

t_list		*create_chained_list(int ac, char **av);
int			*check_args(int ac, char **av, unsigned int *size);
void		create_stack_b(t_list **stack_a, t_list **stack_b);

char		**get_array(int ac, char **av);
int			*convert_array_to_int(char **array);
char		**get_array_single_arg(char *av);
char		**get_array_multiple_args(int ac, char **av);
//int			get_steps(long int cost_a, long int cost_b);
void		get_target_position_stack(t_list *stack_a, t_list *stack_b);
void		get_position_stack(t_list *stack_a, t_list *stack_b);

void		sort_morethan_three(t_list **stack_a, t_list **stack_b);

void		chose_and_do_rr_or_r(t_list **stack_a, t_list **stack_b, \
			long int cost_a, long int cost_b);

void		get_index(t_list *stack_a);

t_list		*sort_upto_three(t_list **stack_a);
void		sort_morethan_three(t_list **stack_a, t_list **stack_b);

t_bool		is_stacks_sort(t_list *stack_a, t_list *stack_b);

void		free_double_ptr_char(char **arr_char);
void		exit_print(char *str);
long int	ft_abs(long int nbr);
void		display_error_message(char **array);

/*
** @brief Swap the first 2 elements at the top of stack a and b.
** Do nothing if there is only one or no elements.
** 
** @param stack_a 
** @param stack_b 
*/
void		ss(t_list **stack_a, t_list **stack_b, t_bool silent);

/*
** @brief Swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
** 
** @param stack_a 
*/
void		sa(t_list **stack_a, t_bool silent);

/*
** @brief Swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
** 
** @param stack_b 
*/
void		sb(t_list **stack_b, t_bool silent);

/*
** @brief Take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
** 
** @param stack_a 
** @param stack_b 
*/
void		pa(t_list **stack_a, t_list **stack_b, t_bool silent);

/*
** @brief Take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
** 
** @param stack_a 
** @param stack_b 
*/
void		pb(t_list **stack_a, t_list **stack_b, t_bool silent);

/*
** @brief Shift up all elements of stack a by 1.
** The first element becomes the last one.
** 
** @param stack_a 
*/
void		ra(t_list **stack_a, t_bool silent);

/*
** @brief Shift up all elements of stack b by 1.
** The first element becomes the last one.
** 
** @param stack_b 
*/
void		rb(t_list **stack_b, t_bool silent);

/*
** @brief Shift up all elements of stack a and b by 1.
** The first element becomes the last one.
** 
** @param stack_a 
** @param stack_b 
*/
void		rr(t_list **stack_a, t_list **stack_b, t_bool silent);

/*
** @brief Shift down all elements of stack a by 1.
** The last element becomes the first one.
** 
** @param stack_a 
*/
void		rra(t_list **stack_a, t_bool silent);

/*
** @brief Shift down all elements of stack b by 1.
** The last element becomes the first one.
** 
** @param stack_b 
*/
void		rrb(t_list **stack_b, t_bool silent);

/*
** @brief Shift down all elements of stack a and b by 1.
** The last element becomes the first one.
** 
** @param stack_a 
** @param stack_b 
*/
void		rrr(t_list **stack_a, t_list **stack_b, t_bool silent);

#endif