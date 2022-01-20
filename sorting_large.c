/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:33:29 by bterral           #+#    #+#             */
/*   Updated: 2022/01/20 16:28:12 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int			a_size;

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
	tmp = a->head;
	while (i < max_bits)
	{
		a_size = a->size;
		while (tmp && j < a_size)
		{
			if (((tmp->expected_pos >> i) & 1) == 0)
			{
				tmp = tmp->next;
				print_action("ra", a, b);
			}
			else
			{
				tmp = tmp->next;
				print_action("pb", a, b);
			}
			j++;
		}
		print(a->head);
		printf("\n");
		print(b->head);
		while (b->head!= NULL)
		{
			printf("b->head->nb : %d\n", b->head->nb);
			print_action("pa", a, b);
			printf("\na stack: ");
			print(a->head);
			printf("\n");
		}
		i++;
	}
}