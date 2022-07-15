/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:11:03 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 14:29:35 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_print(char *str)
{
	ft_putstr_fd("Error message : ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_double_ptr_char(char **arr_char)
{
	size_t	i;

	i = 0;
	while (arr_char[i])
	{
		free(arr_char[i]);
		i++;
	}
}
