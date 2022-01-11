/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:10:07 by bterral           #+#    #+#             */
/*   Updated: 2022/01/11 17:55:34 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**init_parsing_args(int argc, char **argv)
{
	char	**output;
	int 	i;

	output = malloc(sizeof(char **) * (argc));
	i = 1;
	while (i < argc)
	{
		output[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	output[i - 1] = 0;
	return (output);
}

void	create_stack(t_element **stack, char **nbs, t_element *tmp)
{
	int	i;

	i = 0;
	while (nbs[i])
	{
		tmp = ft_lstnew(ft_atoi(nbs[i]));
		ft_lstadd_back(stack, tmp);
		i++;
	}
}

int	error_message(char **nbs)
{
	int	i;

	i = 0;
	while (nbs[i])
	{
		free(nbs[i]);
		i++;
	}
	free(nbs);
	write(2, "Error\n", 6);
	return (0);
}

int	error_figures(char **nbs)
{
	int	i;
	int	j;

	i = 0;
	while (nbs[i])
	{
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

int	main(int argc, char **argv)
{
	char		**nbs;
	t_element	*a;
	t_element	tmp;

	// a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		nbs = ft_split(argv[1], ' ');
	else
		nbs = init_parsing_args(argc, argv);
	if (error_figures(nbs))
		return (error_message(&*nbs));
	create_stack(&**a, &*nbs, &tmp);
	return (0);
}