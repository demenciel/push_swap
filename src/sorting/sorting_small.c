/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:31:39 by acouture          #+#    #+#             */
/*   Updated: 2023/04/01 09:06:51 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sorting_5(t_data *data)
{
	t_pile	**lst;
	int		min;
	int		new_min;

	lst = data->pile_a;
	min = find_min(lst, 5);
	data_on_top(lst, 'a', min);
	push_b(data);
	new_min = find_min(lst, 4);
	data_on_top(lst, 'a', new_min);
	push_b(data);
	sorting_3(data);
	push_a(data);
	push_a(data);
}

void	sorting_4(t_data *data)
{
	int	min;

	min = find_min(data->pile_a, 4);
	data_on_top(data->pile_a, 'a', min);
	push_b(data);
	sorting_3(data);
	push_a(data);
}

void	sorting_3_moves(t_data *data, int a, int b, int c)
{
	if (a > b && a < c)
		swap(data->pile_a, 'a', true);
	if (a > b && b > c)
	{
		first_to_last(data->pile_a, 'a', true);
		swap(data->pile_a, 'a', true);
	}
	if (a > c && b < c)
		first_to_last(data->pile_a, 'a', true);
	if (a < c && b > c)
	{
		swap(data->pile_a, 'a', true);
		first_to_last(data->pile_a, 'a', true);
	}
	if (a < b && a > c)
		last_to_first(data->pile_a, 'a', true);
}

void	sorting_3(t_data *data)
{
	t_pile	*top;
	t_pile	*mid;
	t_pile	*bottom;

	top = *data->pile_a;
	mid = top->next;
	if (data->size_pile_a == 1)
		return ;
	if (data->size_pile_a < 3)
	{
		sorting_under_3(data, *(top->data), *(mid->data));
		return ;
	}
	bottom = mid->next;
	sorting_3_moves(data, *(top->data), *(mid->data), *(bottom->data));
}

void	sorting(t_data *data)
{
	if (data->size_pile_a <= 3)
		sorting_3(data);
	else if (data->size_pile_a == 4)
		sorting_4(data);
	else if (data->size_pile_a == 5)
		sorting_5(data);
	else if (data->size_pile_a <= 100)
		sorting_100(data);
	else
		sorting_big(data);
}
