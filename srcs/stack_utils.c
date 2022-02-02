/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:47:41 by bterral           #+#    #+#             */
/*   Updated: 2022/02/02 11:16:19 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*initiliaze_empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = NULL;
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
		ft_lstadd_back(&stack->head, tmp);
		stack->size++;
		i++;
	}
	return (stack);
}

int	check_duplicate(t_stack *stack)
{
	t_element	*tmp1;
	t_element	*tmp2;

	tmp1 = stack->head;
	//is it OK if stack is one element
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while(tmp2)
		{
			if (tmp1->nb == tmp2->nb)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
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