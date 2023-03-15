/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:31:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 15:36:34 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    sorting_under_3(t_data *data)
{
    t_pile_a *pa;
    
    pa = data->pile_a;
    // if (pa->data > pa->next->data)
    //     swap_a(data);
    // if (pa->data > pa->next->data)
    //     rotate_a(data);
}

void    sorting(t_data *data)
{
    sorting_under_3(data);
    t_pile_a *pa;

    pa = data->pile_a;
    while (pa != NULL)
    {
        ft_printf("%d\n", pa->data);
        pa = pa->next;
    }
}