/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:57:24 by bterral           #+#    #+#             */
/*   Updated: 2022/01/17 17:36:31 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_element
{
	struct s_element *next;
	int				nb;
}	t_element;

typedef struct	s_stack
{
	t_element	*head;
	int			size;
}	t_stack;

////////////////////////////////////////
//         parsing_utils              //
////////////////////////////////////////

int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
void		ft_lstadd_back(t_element **alst, t_element *new);
t_element	*ft_lstnew(int nb);

////////////////////////////////////////
//         stack functions            //
////////////////////////////////////////

void		push(t_stack *from, t_stack *to);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

////////////////////////////////////////
//         sorting algorithm          //
////////////////////////////////////////

int		is_sorted(t_stack *stack);
void	algorithm_selection(t_stack *a, t_stack *b);
void	print_action(char *action, t_stack *a, t_stack *b);
void	three_values(t_stack *a, t_stack *b);
void	four_values(t_stack *a, t_stack *b);
void five_values(t_stack *a, t_stack *b);

#endif