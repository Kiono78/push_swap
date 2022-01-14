/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:10:07 by bterral           #+#    #+#             */
/*   Updated: 2022/01/14 10:55:14 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initiliaze_empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = 0;
	return (stack);
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
	t_stack		*stack;

	stack = initiliaze_empty_stack();
	stack->head = ft_lstnew(ft_atoi(nbs[1]));
	if (!stack->head)
		return (NULL);
	stack->size++;
	i = 2;
	while (nbs[i])
	{
		tmp = ft_lstnew(ft_atoi(nbs[i]));
		if (!tmp)
			return (free_piles(stack->head));
		ft_lstadd_back(&stack->head, ft_lstnew(ft_atoi(nbs[i])));
		stack->size++;
		i++;
	}
	return (stack);
}

int	error_message()
{
	write(2, "Error\n", 6);
	return (0);
}

int	error_figures(char **nbs)
{
	int	i;
	int	j;

	i = 1;
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

void print(t_element *head) 
{
    t_element *current_node = head;
   	while ( current_node != NULL) 
	{
        printf("%d ", current_node->nb);
        current_node = current_node->next;
    }
}

int	main(int argc, char **argv)
{
	char		**nbs;
	t_stack		*a;
	t_stack		*b;
	t_element	*push_new;

	if (argc < 2)
		return (0);
	if (error_figures(argv))
		return (error_message());
	a = create_stack(argv);
	if (!a)
		return (error_message());
	print(a->head);
	push_new = push(56, a);
	printf("\n");
	print(a->head);
	printf("\n");
	swap(a);
	print(a->head);
	printf("\n");
	rotate(a);
	print(a->head);
	printf("\n");
	reverse_rotate(a);
	print(a->head);
	return (0);
}