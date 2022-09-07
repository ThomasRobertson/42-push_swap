/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:36:04 by troberts          #+#    #+#             */
/*   Updated: 2022/09/07 19:40:29 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack_b(t_list **stack_a, t_list **stack_b)
{
	size_t	size;
	size_t	i;
	size_t	j;

	*stack_b = NULL;
	size = ft_lstsize(*stack_a);
	j = size;
	while (j && size > 5)
	{
		if ((*stack_a)->content->index > size / 2)
			pb(stack_a, stack_b, false);
		else
			ra(stack_a, false);
		j--;
	}
	i = 0;
	size = ft_lstsize(*stack_a);
	if (size <= 3)
		return ;
	while (i < (size - 3))
	{
		pb(stack_a, stack_b, false);
		i++;
	}
}

char	**get_array(int ac, char **av)
{
	char	**array;

	if (ac == 2)
		array = get_array_single_arg(av[1]);
	else
		array = get_array_multiple_args(ac, av);
	if (array==NULL || *array == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
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
	if (array_int == NULL)
		return (NULL);
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
	unsigned int	j;

	array = malloc(sizeof(*array) * ((ac - 1) + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ((unsigned int)ac - 1))
	{
		array[i] = ft_strdup(av[i + 1]);
		if (array[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(array[j]);
				j++;
			}
			free(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
