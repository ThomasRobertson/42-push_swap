/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:12:41 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 14:29:22 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_bigger_then_int(char **array)
{
	size_t	i;
	size_t	j;
	size_t	lenght_int;
	size_t	lenght;

	i = 0;
	j = 0;
	lenght_int = 10;
	while (array[i])
	{
		j = 0;
		lenght = 0;
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j++]))
				lenght++;
		}
		if (lenght > lenght_int || ft_atol(array[i]) > INT_MAX || \
			ft_atol(array[i]) < INT_MIN)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

static void	check_duplicate(int *array, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	counter;

	i = 0;
	while (i < size)
	{
		j = 0;
		counter = 0;
		while (j < size)
		{
			if (array[i] == array[j])
				counter++;
			j++;
		}
		if (counter != 1)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	check_formats_args(char **array)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j]) || ft_isspace(array[i][j]))
				j++;
			else if ((array[i][j] == '+' || array[i][j] == '-') && \
				(ft_isdigit(array[i][j + 1]) || ft_isspace(array[i][j + 1])))
				j++;
			else
			{
				ft_putendl_fd("Error", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

t_bool	check_args(int ac, char **av, int **array_int, unsigned int *size)
{
	char			**array_char;

	array_char = get_array(ac, av);
	check_formats_args(array_char);
	*size = 0;
	while (array_char[*size])
		(*size)++;
	*array_int = convert_array_to_int(array_char);
	check_duplicate(*array_int, *size);
	check_bigger_then_int(array_char);
	free_double_ptr_char(array_char);
	return (true);
}
