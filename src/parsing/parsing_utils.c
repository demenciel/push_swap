/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/04/07 13:19:33 by acouture         ###   ########.fr       */
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
	if (data->args != NULL)
		free_args(data);
	free_list(*data->pile_a);
	free_struct(data);
	(void)s;
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

void	check_fit(char *s, t_data *data)
{
	int		count;
	int		is_negative;
	char	*min_val;

	count = 0;
	is_negative = 0;
	min_val = "-2147483648";
	if (*s == '-')
	{
		is_negative = 1;
		s++;
	}
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			ft_error_push("", data);
		count++;
		s++;
	}
	if (count > 10 || (count == 10 && (ft_strncmp(s - count, "2147483647",
					count) > 0 || (is_negative && ft_strncmp(s - count, min_val
						+ 1, count) > 0))))
		ft_error_push("", data);
}

int	ft_atoi_int(char *s, t_data *data)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	check_word(s, data);
	check_fit(s, data);
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
