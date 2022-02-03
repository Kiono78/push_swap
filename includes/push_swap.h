/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:57:24 by bterral           #+#    #+#             */
/*   Updated: 2022/02/03 11:20:28 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_element
{
	struct s_element *next;
	int				nb;
	int				expected_pos;
}	t_element;

typedef struct	s_stack
{
	t_element	*head;
	int			size;
}	t_stack;

////////////////////////////////////////
//         parsing_utils              //
////////////////////////////////////////

char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
void		ft_lstadd_back(t_element **alst, t_element *new);
t_element	*ft_lstnew(int nb);
long		ft_atol(const char *str);
void 		print(t_element *head);

////////////////////////////////////////
//        error management            //
////////////////////////////////////////

int	error_message();
int	error_figures(char **nbs);

////////////////////////////////////////
//         stack creation             //
////////////////////////////////////////

t_stack	*create_stack(char **nbs);
int	check_duplicate(t_stack *stack);
t_stack	*free_piles(t_element *head);
t_stack	*initiliaze_empty_stack(void);
void	free_all(t_stack *a, t_stack *b);

////////////////////////////////////////
//         stack functions            //
////////////////////////////////////////

void		push(t_stack *from, t_stack *to);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
int			is_sorted(t_stack *stack);

////////////////////////////////////////
//     sorting small algorithm        //
////////////////////////////////////////

void		algorithm_selection(t_stack *a, t_stack *b);
void		print_action(char *action, t_stack *a, t_stack *b);
void		three_values(t_stack *a, t_stack *b);
void		four_values(t_stack *a, t_stack *b);
void 		five_values(t_stack *a, t_stack *b);
void		push_lower_to_b(t_stack *a, t_stack *b);

////////////////////////////////////////
//     sorting large algorithm        //
////////////////////////////////////////

void 		sort_large(t_stack *a, t_stack *b);
int			*create_ordered_array(t_stack *a);
int			*sort_array(t_stack *a, int *array);

#endif