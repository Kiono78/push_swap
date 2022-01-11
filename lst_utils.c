/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:35:56 by bterral           #+#    #+#             */
/*   Updated: 2022/01/11 17:18:40 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->nb = nb;
		new->next = NULL;
	}
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*lst;

	if (*alst)
	{
		if (alst)
		{
			lst = ft_lstlast(*alst);
			lst->next = new;
		}
	}
	else
		*alst = new;
}
