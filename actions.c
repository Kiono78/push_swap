/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:34:38 by bterral           #+#    #+#             */
/*   Updated: 2022/01/14 11:09:35 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*push(int nb, t_stack *stack)
{
	t_element	*node;

	node = (t_element *)malloc(sizeof(t_element));
	if (!node)
	{
		printf("stack overflow\n");
		// return (free_everything());
	}
	node->nb = nb;
	node->next = stack->head;
	stack->head = node;
	stack->size++;
	return (node);
}

void	swap(t_stack *stack)
{
	t_element	*new_first;
	t_element	*new_second;

	if (!stack->head)
		return ;
	new_second = stack->head;
	if (new_second->next == NULL)
		return ;
	new_first = new_second->next;
	new_second->next = new_first->next;
	new_first->next = new_second;
	stack->head = new_first;
}

void	rotate(t_stack *stack)
{
	t_element	*tmp;
	t_element	*new_last;

	new_last = stack->head;
	tmp = stack->head->next;
	new_last->next = NULL;
	stack->head = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_last;
}

void	reverse_rotate(t_stack *stack)
{
	t_element	*last;
	t_element	*second_to_last;

	last = stack->head;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	last->next = stack->head;
	stack->head = last;
	second_to_last->next = NULL;
}