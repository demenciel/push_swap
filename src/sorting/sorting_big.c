/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:55:24 by acouture          #+#    #+#             */
/*   Updated: 2023/03/30 16:34:14 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    sorting_big(t_data *data)
{
    int median;
    int median_add;
    int len;
    int y;

    median = avg_of_pile(data->pile_a, data->size_pile_a) / 8;
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
        median += median_add;
    }
    sort_a_100(data);
    b_to_a(data);
}
