/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:33:29 by bterral           #+#    #+#             */
/*   Updated: 2022/01/18 14:27:28 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_stack *a)
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

int	sort_array(t_stack *a, int *array)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < (a->size - 1))
	{
		printf("array[%d] : %d\n", i,array[i]);
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
	printf("a->size : %d\n", a->size);
	return (array[a->size / 2]);
}

void sort_large(t_stack *a, t_stack *b)
{
	a->median = find_median(a);
	printf("median : %d", a->median);
}