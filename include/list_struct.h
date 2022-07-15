/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:50:18 by troberts          #+#    #+#             */
/*   Updated: 2022/07/12 17:55:48 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_STRUCT_H
# define LIST_STRUCT_H

# define T_LIST

typedef struct s_stack
{
	int				value;
	long int		index;
	long int		pos;
	long int		target_pos;
	long int		cost_a;
	long int		cost_b;
}					t_stack;

typedef struct s_list
{
	t_stack			*content;
	struct s_list	*next;
}					t_list;

#endif