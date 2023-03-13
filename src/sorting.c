/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:31:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/13 14:27:05 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    sorting_under_3(t_data *data)
{
    int i;
    (void)data;
    i = 0;
    push_a(data);
    // swap_swap(data);
}

void    sorting(t_data *data)
{
    copy_a_to_b(data, data->size_pile_a);
    sorting_under_3(data);
    for (int i = 0; i < data->size_pile_a; i++) {
        ft_printf("%d\n", data->pile_a[i]);
    }
    ft_printf("\n");
    
    for (int i = 0; i < data->size_pile_b; i++) {
        ft_printf("%d\n", data->pile_b[i]);
    }
}