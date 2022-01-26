/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:34:38 by bterral           #+#    #+#             */
/*   Updated: 2022/01/24 13:43:47 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push(t_element *ele, t_stack *stack)
// {
// 	t_element	*node;

// 	node = (t_element *)malloc(sizeof(t_element));
// 	if (!node)
// 	{
// 		printf("stack overflow\n");
// 		// return (free_everything());
// 	}
// 	node->nb = nb;
// 	node->next = stack->head;
// 	stack->head = node;
// 	stack->size++;
// 	return (node);
// }

void	print_action(char *action, t_stack *a, t_stack *b)
{
	if (ft_strncmp(action, "sa", 2) == 0)
	{
		ft_putstr_fd("sa\n", 1);
		swap(a);
	}
	else if (ft_strncmp(action, "ra", 2) == 0)
	{
		ft_putstr_fd("ra\n", 1);
		rotate(a);
	}
	else if (ft_strncmp(action, "rra", 3) == 0)
	{
		ft_putstr_fd("rra\n", 1);
		reverse_rotate(a);
	}
	else if (ft_strncmp(action, "pa", 2) == 0)
	{
		ft_putstr_fd("pa\n", 1);
		push(b, a);
	}
	else if (ft_strncmp(action, "pb", 2) == 0)
	{
		ft_putstr_fd("pb\n", 1);
		push(a, b);
	}
}

void	push(t_stack *from, t_stack *to)
{
	t_element	*node;

	node = from->head;
	from->head = from->head->next;
	from->size--;
	if (!node)
		return ;
	if (to->head)
	{
		node->next = to->head;
		to->head = node;
	}
	else
	{
		to->head = node;
		node->next = NULL;
	}
	to->size++;
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
