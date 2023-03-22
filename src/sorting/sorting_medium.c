/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:40:07 by acouture          #+#    #+#             */
/*   Updated: 2023/03/22 15:37:25 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    sorting_100(t_data *data)
{
    t_pile *node;
    t_pile *node_b;
    int min;
    int len;

    len = lst_len(data->pile_a);
    node = *data->pile_a;
    min = find_min(data->pile_a, len / 2);
    data_on_top(data->pile_a, 'a', min);
    push_b(data);
    len /= 2;
    while (len)
    {
        node_b = *data->pile_b;
        push_b(data);
        if (node->data > node_b->data)
            first_to_last(data->pile_b, 'b', true);
        else
            last_to_first(data->pile_b, 'b', true);
        len--;
    }
    len = lst_len(data->pile_a);
    while (len)
    {
        node_b = *data->pile_b;
        push_b(data);
        if (node->data > node_b->data)
            first_to_last(data->pile_b, 'b', true);
        len--;
    }
}