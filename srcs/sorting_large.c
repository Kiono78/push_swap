/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:33:29 by bterral           #+#    #+#             */
/*   Updated: 2022/02/04 10:20:17 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*create_ordered_array(t_stack *a)
{
	int			*array;
	int			i;
	t_element	*tmp;

	array = (int *)malloc(sizeof(int) * a->size);
	if (!array)
		return (0);
	tmp = a->head;
	i = 0;
	while (tmp)
	{
		array[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	return (sort_array(a, array));
}

int	*sort_array(t_stack *a, int *array)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < (a->size - 1))
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = tmp;
			i = 0;
		}
	}
	return (array);
}

void	stack_assign_index(t_stack *stack, int *array)
{
	t_element	*tmp;
	int			i;

	tmp = stack->head;
	while (tmp)
	{
		i = 0;
		while (i < stack->size)
		{
			if (tmp->nb == array[i])
				tmp->expected_pos = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	large_actions_algorithm(t_stack *a, t_stack *b, int max_bits)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	size = a->size;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->head->expected_pos >> i) & 1) == 1)
				print_action("ra", a, b);
			else
				print_action("pb", a, b);
			j++;
		}
		while (b->head != NULL)
			print_action("pa", a, b);
		i++;
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int			*array;
	int			max_bits;

	array = create_ordered_array(a);
	stack_assign_index(a, array);
	max_bits = 0;
	while (((a->size - 1) >> max_bits) != 0)
		max_bits++;
	large_actions_algorithm(a, b, max_bits);
}
