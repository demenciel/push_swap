/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:02:56 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 15:31:32 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    rotate_a(t_data *data)
{
    t_pile_a *first;
    t_pile_a *last;
    t_pile_a *prev_last;
    int temp;

    first = data->pile_a;
    last = data->pile_a;
    prev_last = NULL;
    while (last->next != NULL)
    {
        prev_last = last;
        last = last->next;
    }
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    ft_printf("ra\n");
}

void    rotate_b(t_data *data)
{
    (void)data;   
}