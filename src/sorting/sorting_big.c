/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:55:24 by acouture          #+#    #+#             */
/*   Updated: 2023/03/30 14:33:03 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_a_500(t_data *data)
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

void    sorting_big(t_data *data)
{
    int median;
    int median_add;
    int len;
    int y;

    median = avg_of_pile(data->pile_a, data->size_pile_a) / 6;
    median_add = median;
    len = data->size_start_pile;
    while (median < (len - (median_add * 2)))
    {
        y = 0;
        while ((y <= median))
        {
            if ((*data->pile_a)->data > median)
                first_to_last(data->pile_a, 'a', true);
            else
                push_b(data);
            y++;
        }
        ft_printf("%d\n", median);
        median += median_add;
    }
    sort_a_500(data);
    b_to_a(data);
}