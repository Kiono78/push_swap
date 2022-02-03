/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:35:56 by bterral           #+#    #+#             */
/*   Updated: 2022/02/03 09:35:20 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*ft_lstnew(int nb)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof(t_element));
	if (new)
	{
		new->nb = nb;
		new->next = NULL;
	}
	return (new);
}

t_element	*ft_lstlast(t_element *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_element **alst, t_element *new)
{
	t_element	*lst;

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
