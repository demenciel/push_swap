/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:50:56 by acouture          #+#    #+#             */
/*   Updated: 2023/03/13 14:25:38 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	copy_a_to_b(t_data *data, int len)
{
	int	i;

	i = 0;
	data->pile_b = malloc(sizeof(int) * len);
	data->size_pile_b = len + 1;
	while (i < len)
	{
		data->pile_b[i] = data->pile_a[i];
		i++;
	}
}

void	check_fit(char *s)
{
	int		count;
	char	*max_nb;
	int		i;
	int		maybe;

	max_nb = "2147483647";
	i = -1;
	count = ft_strlen(s);
	if (count > 10)
		ft_error(": Number too big");
	maybe = 10 == count;
	while (++i < count)
	{
		if (maybe && s[i] > max_nb[i])
			ft_error(": Number too big");
		if (s[i] < max_nb[i])
			maybe = 0;
	}
}

int	ft_atoi_int(char *str)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	check_fit(str);
	if (!str)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
