/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:31:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 10:17:05 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    sorting_under_3(t_data *data)
{
    push_b(data);
    push_b(data);
    // swap_swap(data);
}

void    sorting(t_data *data)
{
    sorting_under_3(data);
    while (data->pile_a != NULL)
    {
        ft_printf("%d\n", data->pile_a->data);
        data->pile_a = data->pile_a->next;
    }
    ft_printf("\n");
    while (data->pile_b != NULL)
    {
        ft_printf("%d\n", data->pile_b->data);
        data->pile_b = data->pile_b->next;
    }

    // for (int i = 0; i < data->size_pile_a; i++) {
    //     ft_printf("%d\n", data->pile_a[i]);
    // }
    // ft_printf("\n");
    
    // for (int i = 0; i < data->size_pile_b; i++) {
    //     ft_printf("%d\n", data->pile_b[i]);
    // }
}