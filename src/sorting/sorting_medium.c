/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:40:07 by acouture          #+#    #+#             */
/*   Updated: 2023/03/30 16:45:22 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	b_to_a(t_data *data)
{
	int	max;

	while (data->size_pile_b > 1)
	{
		max = find_max(data->pile_b, data->size_pile_b);
		data_on_top(data->pile_b, 'b', max);
		push_a(data);
	}
	push_a(data);
}

void	sort_a_100(t_data *data)
{
	int	min;
	int	transfer;

	transfer = 0;
	while (data->size_pile_a > 5)
	{
		min = find_min(data->pile_a, data->size_pile_a);
		data_on_top(data->pile_a, 'a', min);
		push_b(data);
		transfer++;
	}
	if (data->size_pile_a > 4)
		sorting_5(data);
	else if (data->size_pile_a == 4)
		sorting_4(data);
	else
		sorting_3(data);
	while (transfer)
	{
		push_a(data);
		transfer--;
	}
}

void	sort_b_half(t_data *data)
{
	int avg;

	avg = avg_of_pile(data->pile_a, data->size_pile_a) / 2;
	if ((*data->pile_b)->next == NULL)
		return ;
	if ((*data->pile_b)->data < avg)
		first_to_last(data->pile_b, 'b', true);
}

void	pre_sort_b(t_data *data)
{
	int	len;
	int	avg;

	avg = avg_of_pile(data->pile_a, data->size_pile_a);
	len = data->size_pile_a;
	while (len > (len / 2))
	{
		if ((*data->pile_a)->data >= avg)
			first_to_last(data->pile_a, 'a', true);
		else
			push_b(data);
		len--;
	}
}

void	sorting_100(t_data *data)
{
	int	len;
	int	avg;

	avg = avg_of_pile(data->pile_a, data->size_pile_a);
	len = data->size_start_pile;
	while (len)
	{
		if ((*data->pile_a)->data >= avg)
			first_to_last(data->pile_a, 'a', true);
		else
		{
			push_b(data);
			sort_b_half(data);
		}
		len--;
	}
	pre_sort_b(data);
	sort_a_100(data);
	b_to_a(data);
}
