/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:31:40 by bterral           #+#    #+#             */
/*   Updated: 2022/01/24 16:30:33 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return;
	if (a->head->nb < second && second > third && a->head->nb < third)
	{
		print_action("sa", a, b);
		print_action("ra", a, b);
	}
	else if (a->head->nb > second && second < third && a->head->nb < third)
		print_action("sa", a, b);
	else if (a->head->nb < second && second > third && a->head->nb > third)
	{
		print_action("ra", a, b);
		print_action("ra", a, b);
	}
	else if (a->head->nb > second && second < third && a->head->nb > third)
		print_action("ra", a, b);
	else
	{
		print_action("sa", a, b);
		print_action("rra", a, b);
	}
}

void	four_values(t_stack *a, t_stack *b)
{
	print_action("pb", a, b);
	three_values(a, b);
	print_action("pa", a, b);
	if (a->head->nb < a->head->next->nb)
		return;
	else if (a->head->nb > a->head->next->nb && a->head->nb < a->head->next->next->nb)
		print_action("sa", a, b);
	else if (a->head->nb > a->head->next->next->nb && a->head->nb < a->head->next->next->next->nb)
	{
		print_action("rra", a, b);
		print_action("sa", a, b);
		print_action("rra", a, b);
		print_action("rra", a, b);
	}
	else
		print_action("ra", a, b);
}

void five_values(t_stack *a, t_stack *b)
{
	print_action("pb", a, b);
	four_values(a, b);
	print_action("pa", a, b);
	if (a->head->nb < a->head->next->nb)
		return;
	if (a->head->nb > a->head->next->next->next->next->nb)
		print_action("ra", a, b);
	else if (a->head->nb > a->head->next->next->next->nb)
	{ 
		print_action("rra", a, b);
		print_action("sa", a, b);
		print_action("ra", a, b);
		print_action("ra", a, b);
	}
	else if (a->head->nb > a->head->next->next->nb)
	{
		print_action("sa", a, b);
		print_action("ra", a, b);
		print_action("sa", a, b);
		print_action("rra", a, b);
	}
	else if (a->head->nb > a->head->next->nb)
		print_action("sa", a, b);
}
