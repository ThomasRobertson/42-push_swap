/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:12:41 by troberts          #+#    #+#             */
/*   Updated: 2022/09/12 19:40:34 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error_message(char **array)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free_double_ptr_char(array);
	exit(EXIT_FAILURE);
}

static int	check_bigger_then_int(char **array)
{
	size_t	i;
	size_t	j;
	size_t	lenght;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		lenght = 0;
		if (array[i][j] == '+' || array[i][j] == '-')
			j++;
		while (array[i][j] == '0')
			j++;
		while (ft_isdigit(array[i][j]))
		{
			lenght++;
			j++;
		}
		if (lenght > LEN_INT || ft_atol(array[i]) > INT_MAX || \
												ft_atol(array[i]) < INT_MIN)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	check_duplicate(int *array, unsigned int size)
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
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
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
			while (ft_isspace(array[i][j]))
				j++;
			if ((array[i][j] == '+' || array[i][j] == '-'))
				j++;
			if (!ft_isdigit(array[i][j]))
				display_error_message(array);
			while (ft_isdigit(array[i][j]))
				j++;
			if (array[i][j] != '\0')
				display_error_message(array);
		}
		i++;
	}
}

int	*check_args(int ac, char **av, unsigned int *size)
{
	char	**array_char;
	int		*array_int;

	array_char = get_array(ac, av);
	check_formats_args(array_char);
	*size = 0;
	while (array_char[*size])
		(*size)++;
	array_int = convert_array_to_int(array_char);
	if (array_int == NULL)
	{
		free_double_ptr_char(array_char);
		exit(EXIT_FAILURE);
	}
	if (check_duplicate(array_int, *size) == EXIT_FAILURE || \
		check_bigger_then_int(array_char) == EXIT_FAILURE)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		free(array_int);
		free_double_ptr_char(array_char);
		exit(EXIT_FAILURE);
	}
	free_double_ptr_char(array_char);
	return (array_int);
}
