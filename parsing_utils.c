/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:13:36 by bterral           #+#    #+#             */
/*   Updated: 2022/01/11 15:18:27 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

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

char	*ft_strdup(const char *s)
{
	char	*output;
	size_t	i;

	output = (char *)malloc(sizeof(*output) * (ft_strlen(s) + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	s_len;
	size_t	i;
	char	*output;

	if (!s)
		return (NULL);
	sub_len = 0;
	s_len = ft_strlen(s);
	while (sub_len < len && *(s + sub_len) != '\0' && start < s_len)
		sub_len++;
	output = (char *)malloc(sizeof(*s) * (sub_len + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		*(output + i) = *(s + start + i);
		i++;
	}
	*(output + i) = '\0';
	return (output);
}