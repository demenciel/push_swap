/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:02:56 by acouture          #+#    #+#             */
/*   Updated: 2023/03/16 13:12:49 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    first_to_last_a(t_data *data)
{
    t_pile *last_node;
    t_pile *second_node;
    t_pile *first_node;
    
    first_node = *data->pile_a;
    second_node = first_node->next;
    last_node = second_node->next;
    while (last_node->next != NULL)
        last_node = last_node->next;
    last_node->next = first_node;
    first_node->next = NULL;
    *data->pile_a = second_node;
    ft_printf("ra\n");
}

void    last_to_first_a(t_data *data)
{
    t_pile *first_node;
    t_pile *second_to_last_node;
    t_pile *last_node;

    first_node = *data->pile_a;
    second_to_last_node = first_node;
    last_node = first_node->next;
    while (last_node->next != NULL)
    {
        second_to_last_node = last_node;
        last_node = last_node->next;
    }
    second_to_last_node->next = NULL;
    last_node->next = first_node;
    *data->pile_a = last_node;
    ft_printf("rra\n");
}