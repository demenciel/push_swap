/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:40:07 by acouture          #+#    #+#             */
/*   Updated: 2023/03/27 14:10:26 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void b_to_a(t_data *data)
{
	int max;

	while (data->size_pile_b > 1)
	{
		max = find_max(data->pile_b, data->size_pile_b);
		data_on_top(data->pile_b, 'b', max);
		push_a(data);
	}
	push_a(data);
}

void sort_a_100(t_data *data)
{
	int min;
	int transfer;

	transfer = 0;
	while (data->size_pile_a > 3)
	{
		min = find_min(data->pile_a, data->size_pile_a);
		data_on_top(data->pile_a, 'a', min);
		push_b(data);
		transfer++;
	}
	sorting_3(data);
	while (transfer)
	{
		push_a(data);
		transfer--;
	}
}

int	avg_of_pile(t_pile **lst, int pile_size)
{
	int total;
	int avg;
	t_pile *node;

	total = 0;
	avg = 0;
	node = *lst;
	while (node != NULL)
	{
		total += node->data;
		node = node->next;
	}
	avg = total / pile_size;
	return (avg);
}

void	sorting_100(t_data *data)
{
	int avg;
	int len;

	len = data->size_start_pile;
	avg = avg_of_pile(data->pile_a, data->size_pile_a);
	while (len)
	{
		if ((*data->pile_a)->data >= avg)
			first_to_last(data->pile_a, 'a', true);
		else
			push_b(data);
		len--;
	}
	sort_a_100(data);
	b_to_a(data);
}