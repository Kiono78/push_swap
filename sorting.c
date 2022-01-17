/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:31:40 by bterral           #+#    #+#             */
/*   Updated: 2022/01/17 17:53:04 by bterral          ###   ########.fr       */
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

void	algorithm_selection(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		print_action("sa", a, b);
	else if (a->size == 3)
		three_values(a, b);
	else if (a->size == 4)
		four_values(a, b);
	else if (a->size == 5)
		five_values(a, b);
}

void	three_values(t_stack *a, t_stack *b)
{
	int			second;
	int			third;
	
	second = a->head->next->nb;
	third = a->head->next->next->nb;
	if (a->head->nb < second && a->head->nb < third)
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
	print_action("pa", a, b);
	three_values(a, b);
	printf("\n");
	print(a->head);
	print_action("pb", a, b);
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
	print_action("pa", a, b);
	four_values(a, b);
	print_action("pb", a, b);
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

void	print_action(char *action, t_stack *a, t_stack *b)
{
	if (ft_strncmp(action, "pa", 2) == 0)
	{
		ft_putstr_fd("pa\n", 1);
		push(a, b);
	}
	else if (ft_strncmp(action, "sa", 2) == 0)
	{
		ft_putstr_fd("sa\n", 1);
		swap(a);
	}
	else if (ft_strncmp(action, "ra", 2) == 0)
	{
		ft_putstr_fd("ra\n", 1);
		rotate(a);
	}
	else if (ft_strncmp(action, "rra", 2) == 0)
	{
		ft_putstr_fd("rra\n", 1);
		reverse_rotate(a);
	}
	else if (ft_strncmp(action, "pb", 2) == 0)
	{
		ft_putstr_fd("pb\n", 1);
		push(b, a);
	}
}