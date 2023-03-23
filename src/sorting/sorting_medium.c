/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:40:07 by acouture          #+#    #+#             */
/*   Updated: 2023/03/23 11:33:27 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	b_to_a(t_data *data)
{
	int	max_b;
	int	len;
    int i = 2;
    while (i--)
        push_a(data);
    sorting_5(data);
	len = data->size_pile_b;
	while (--len)
	{
		max_b = find_max(data->pile_b, data->size_pile_b);
		data_on_top(data->pile_b, 'b', max_b);
		push_a(data);
	}
	push_a(data);
}
void	sorting_100(t_data *data)
{
	int check_half_b;
	int len;
	int len_check;
	int mini_stack;
	int i;

    i = 4;
	len_check = data->size_pile_a - 5;
	push_b(data);
	len = data->size_pile_a - 5;
	check_half_b = (*data->pile_b)->data;
	while (i--)
	{
	    mini_stack = data->size_start_pile / 4;
		while (mini_stack)
		{
            if (data->size_pile_a < 3)
                break;
			push_b(data);
			if ((*data->pile_a)->data > len_check)
				first_to_last(data->pile_a, 'a', true);
			if ((*data->pile_a)->data < check_half_b)
				first_to_last(data->pile_b, 'b', true);
			mini_stack--;
		}
	}
	b_to_a(data);
}