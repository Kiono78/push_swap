/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:10:07 by bterral           #+#    #+#             */
/*   Updated: 2022/01/12 12:01:19 by bterral          ###   ########.fr       */
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

// void	create_stack(t_element **head, char **nbs)
// {
// 	int			i;

// 	i = 0;
// 	while (nbs[i])
// 	{
// 		ft_lstadd_back(head, ft_lstnew(ft_atoi(nbs[i])));
// 		i++;
// 	}
// }

t_stack	*initiliaze_empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = 0;
	return (stack);
}

void	free_char_tabs(char **nbs)
{
	int	i;

	i = 0;
	while (nbs[i])
	{
		free(nbs[i]);
		i++;
	}
	free(nbs);
}

t_stack	*free_piles(t_element *head)
{
	t_element	*current;
	t_element	*next;

	current = head;
	while (current)
	{
		next = current->next;
		current->nb = 0;
		free(current);
		current = next;
	}
	return (NULL);
}

t_stack	*create_stack(char **nbs)
{
	int			i;
	t_element	*tmp;
	t_element	*head;
	t_stack		*stack;

	stack = initiliaze_empty_stack();
	head = ft_lstnew(ft_atoi(nbs[0]));
	if (!head)
		return (NULL);
	stack->head = head;
	stack->size++;
	i = 1;
	while (nbs[i])
	{
		tmp = ft_lstnew(ft_atoi(nbs[i]));
		if (!tmp)
			return (free_piles);
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(nbs[i])));
		stack->size++;
		i++;
	}
	return (stack);
}

int	error_message(char **nbs)
{
	free_char_tabs(nbs);
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
	t_stack		*a;

	if (argc < 2)
		return (0);
	// if (argc == 2)
	// 	nbs = ft_split(argv[1], ' ');
	// else
	// 	nbs = init_parsing_args(argc, argv);
	nbs = init_parsing_args(argc, argv);
	if (error_figures(nbs))
		return (error_message(&*nbs));
	// a = create_stack(nbs);
	// if a is NULL
	// free_char_tabs(nbs);
	printf("nb[0] : %s", nbs[0]);
	return (0);
}