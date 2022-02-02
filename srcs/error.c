/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:46:26 by bterral           #+#    #+#             */
/*   Updated: 2022/02/02 11:20:12 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_message()
{
	write(2, "Error\n", 6);
	exit(1);
}

int	error_figures(char **nbs)
{
	int	i;
	int	j;

	i = 1;

	while (nbs[i])
	{
		if (!nbs[i][0])
			return (1);
		if ((ft_atol(nbs[i]) < INT_MIN || ft_atol(nbs[i]) > INT_MAX)
			|| ft_strlen(nbs[i]) > 11)
			return (1);
		j = 0;
		if (nbs[i][j] == '-')
			j++;
		while (nbs[i][j])
		{
			if (nbs[i][j] < '0' || nbs[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}