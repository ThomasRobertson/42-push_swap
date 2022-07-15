/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:23:14 by troberts          #+#    #+#             */
/*   Updated: 2022/04/21 22:50:19 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ')
		return (8192);
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (8192);
	else
		return (0);
}
