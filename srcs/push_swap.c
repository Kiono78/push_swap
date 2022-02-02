/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:10:07 by bterral           #+#    #+#             */
/*   Updated: 2022/02/02 11:42:42 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *str)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
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
	else if (a->size > 5)
		sort_large(a, b);
	// free(a);
	// free(b);
	//better to free, my linked list
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	if (error_figures(argv))
		return (error_message());
	a = create_stack(argv);
	if (check_duplicate(a))
		return (error_message());
	if (!a)
		return (error_message());
	b = initiliaze_empty_stack();
	if (is_sorted(a))
		printf("stack is already sorted");
	else
		algorithm_selection(a, b);
	return (0);
}
