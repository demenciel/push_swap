/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:40:07 by acouture          #+#    #+#             */
/*   Updated: 2023/03/25 09:17:49 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void sort_a_100(t_data *data)
{
	int len_half;
	int max;
	int i;
	t_pile *node;

	i = data->size_pile_a - 1;
	len_half = data->size_pile_a / 2;
	while (i)
	{
		node = *data->pile_a;
		max = find_max(data->pile_a, data->size_pile_a);
		while (node != NULL)
		{
			if (node->data == max)
			{
				node->checked = true;
				break;
			}
			node = node->next;
		}
		data_on_top(data->pile_a, 'a', max);
		first_to_last(data->pile_a, 'a', true);
		i--;
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
}