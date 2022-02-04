/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:31:40 by bterral           #+#    #+#             */
/*   Updated: 2022/02/04 10:10:27 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_element	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->next->nb < tmp->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	three_values(t_stack *a, t_stack *b)
{
	int			second;
	int			third;

	second = a->head->next->nb;
	third = a->head->next->next->nb;
	if (a->head->nb < second && second < third)
		return ;
	if (a->head->nb < second && second > third && a->head->nb < third)
	{
		print_action("sa", a, b);
		print_action("ra", a, b);
	}
	else if (a->head->nb > second && second < third && a->head->nb < third)
		print_action("sa", a, b);
	else if (a->head->nb < second && second > third && a->head->nb > third)
		print_action("rra", a, b);
	else if (a->head->nb > second && second < third && a->head->nb > third)
		print_action("ra", a, b);
	else
	{
		print_action("sa", a, b);
		print_action("rra", a, b);
	}
}

void	push_lower_to_b(t_stack *a, t_stack *b)
{
	t_element	*tmp;
	t_element	*min_ptr;
	int			i;

	i = 0;
	tmp = a->head;
	min_ptr = a->head;
	while (tmp)
	{
		if (tmp->nb < min_ptr->nb)
		{
			min_ptr = tmp;
			i++;
		}
		tmp = tmp->next;
	}
	while (min_ptr != a->head)
	{
		if (i < 2)
			print_action("ra", a, b);
		else
			print_action("rra", a, b);
	}
	print_action("pb", a, b);
}

void	four_values(t_stack *a, t_stack *b)
{
	push_lower_to_b(a, b);
	three_values(a, b);
	print_action("pa", a, b);
}

void	five_values(t_stack *a, t_stack *b)
{
	push_lower_to_b(a, b);
	push_lower_to_b(a, b);
	three_values(a, b);
	print_action("pa", a, b);
	print_action("pa", a, b);
}
