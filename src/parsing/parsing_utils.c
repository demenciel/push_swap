/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/04/04 14:26:22 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	check_word(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && !(ft_isdigit(s[i + 1])))
			ft_error("");
		if (!(ft_isdigit(s[i]) || s[i] == '-'))
			ft_error("");
		i++;
	}
}

void	check_fit(char *s)
{
	int		count;
	int		is_negative;
	char	*min_val;

	count = 0;
	is_negative = 0;
	min_val = "-2147483647";
	if (*s == '-')
	{
		is_negative = 1;
		s++;
	}
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			ft_error("");
		count++;
		s++;
	}
	if (count > 10 || (count == 10 && (ft_strncmp(s - count, "2147483647",
					count) > 0 || (is_negative && ft_strncmp(s - count, min_val
						+ 1, count) > 0))))
		ft_error("");
}

void	check_error(char c)
{
	if (c >= '9' && c <= '0')
		ft_error("");
}

int	ft_atoi_int(char *s)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	check_word(s);
	check_fit(s);
	while (*s <= 32)
		s++;
	if (*s == '-')
	{
		sign = -sign;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}
