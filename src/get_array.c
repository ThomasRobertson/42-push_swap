/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:36:04 by troberts          #+#    #+#             */
/*   Updated: 2022/07/15 14:28:56 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_array(int ac, char **av)
{
	char	**array;

	if (ac == 2)
		array = get_array_single_arg(av[1]);
	else
		array = get_array_multiple_args(ac, av);
	return (array);
}

int	*convert_array_to_int(char **array)
{
	int				*array_int;
	unsigned int	i;
	unsigned int	size;

	size = 0;
	while (array[size])
		size++;
	array_int = malloc(sizeof(*array_int) * size);
	i = 0;
	while (i < size)
	{
		array_int[i] = ft_atoi(array[i]);
		i++;
	}
	return (array_int);
}

char	**get_array_single_arg(char *av)
{
	char	**array;

	array = ft_split(av, ' ');
	return (array);
}

char	**get_array_multiple_args(int ac, char **av)
{
	char			**array;
	unsigned int	i;

	array = malloc(sizeof(*array) * ((ac - 1) + 1));
	i = 0;
	while (i < ((unsigned int)ac - 1))
	{
		array[i] = ft_strdup(av[i + 1]);
		i++;
	}
	array[i] = NULL;
	return (array);
}
