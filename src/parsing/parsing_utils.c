/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/04/01 09:20:45 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	check_word(char *s)
{
	while (*s)
	{
		if (!(ft_isdigit(*s) || *s == '-'))
			ft_error("");
		s++;
	}
}

void	check_fit(char *s)
{
	int		count;
	int		i;
	char	*max_nb;
	int		maybe_big;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == '-')
			count--;
		++count;
	}
	if (count > 10)
		ft_error("");
	maybe_big = 10 == count;
	max_nb = "2147483647";
	i = -1;
	while (++i < count)
	{
		if (maybe_big && s[i] > max_nb[i])
			ft_error("");
		if (s[i] < max_nb[i])
			maybe_big = 0;
	}
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
