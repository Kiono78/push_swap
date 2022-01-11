/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:57:24 by bterral           #+#    #+#             */
/*   Updated: 2022/01/11 17:55:08 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct frame

typedef struct s_element
{
	struct s_stack *next;
	// struct s_stack *previous;
	int				nb;
}	t_element;

////////////////////////////////////////
//         parsing_utils              //
////////////////////////////////////////

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
t_stack	*ft_lstnew(int nb);

#endif