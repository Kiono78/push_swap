/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:33:29 by bterral           #+#    #+#             */
/*   Updated: 2022/02/02 10:43:40 by bterral          ###   ########.fr       */
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

void sort_large(t_stack *a, t_stack *b)
{
	int			*array;
	t_element	*tmp;
	int			i;
	int			max_bits;
	int			j;
	int			size;

	//Array should be at least unsigned int, or long
	array = create_ordered_array(a);
	tmp = a->head;
	while (tmp)
	{
		i = 0;
		while (i < a->size)
		{
			if (tmp->nb == array[i])
				tmp->expected_pos = i;
			i++;
		}
		tmp = tmp->next;
	}
	max_bits = 0;
	while (((a->size - 1) >> max_bits) != 0)
		max_bits++;
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
		while (b->head!= NULL)
			print_action("pa", a, b);
		i++;
	}
}