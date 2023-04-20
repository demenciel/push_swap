/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/04/20 14:04:35 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	check_split(t_data *data)
{
	if (*data->args == NULL)
		ft_error_push("", data);
}

void	ft_error_push(char *s, t_data *data)
{
	(void)s;
	if (data->args != NULL)
		free_args(data);
	free_list(*data->pile_a);
	free_struct(data);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_word(char *s, t_data *data)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && !(ft_isdigit(s[i + 1])))
			ft_error_push("", data);
		if (!(ft_isdigit(s[i]) || s[i] == '-'))
			ft_error_push("", data);
		i++;
	}
}

void	check_fit(long n, t_data *data)
{
	if (n > INT_MAX || n < INT_MIN)
		ft_error_push("", data);
	(void)data;
}

long	ft_atoi_int(char *s, t_data *data)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	check_word(s, data);
	while (*s <= 32)
		s++;
	if (*s == '-')
	{
		sign = -sign;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}
