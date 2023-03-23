/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:40:07 by acouture          #+#    #+#             */
/*   Updated: 2023/03/23 08:13:36 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    sorting_100(t_data *data)
{
    int check_half_b;
    int len;
    int len_2;

    push_b(data);
    len = lst_len(data->pile_a) - 1;
    check_half_b = (*data->pile_b)->data;
    len_2 = len;
    while (len && *data->pile_a != NULL)
    {
        if (*data->pile_a && (*data->pile_a)->data < check_half_b)
            first_to_last(data->pile_b, 'b', true);
        push_b(data);
        len--;
    }
}