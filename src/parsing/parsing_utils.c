/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 14:19:24 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_pile_a	*new_node_a(int data, int index)
{
	t_pile_a	*new;

	new = (t_pile_a *)malloc(sizeof(t_pile_a));
	new->data = data;
	new->index = index;
	new->next = NULL;
	return (new);
}

t_pile_b	*new_node_b(int data)
{
	t_pile_b	*new;

	new = (t_pile_b *)malloc(sizeof(t_pile_b));
	new->data = data;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	check_word(char *s)
{
	while (*s)
	{
		if (!(ft_isdigit(*s)))
			ft_error("Not a number");
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
		ft_error("Number too big");
	maybe_big = 10 == count;
	max_nb = "2147483647";
	i = -1;
	while (++i < count)
	{
		if (maybe_big && s[i] > max_nb[i])
			ft_error("Number too big");
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
		sign = -sign;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}
