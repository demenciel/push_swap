/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 07:56:11 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// void    check_for_doubles(t_data *data)
// {
//     int i;
//     int j;
    
//     i = 0;
//     copy_a_to_b(data, data->size_pile_a);
//     while (i < data->size_pile_a)
//     {
//         j = i + 1;
//         while (j < data->size_pile_a)
//         {
//             if (data->pile_a[i] == data->pile_b[j])
//                 ft_error(": Double");
//             j++;
//         }
//         i++;
//     }
//     free(data->pile_b);
// }

void    args_to_pile_a(t_data *data, char **av)
{
    int i;
    int nb;
    t_pile_a *new;
    
    i = 1;
    while (av[i])
    {
        nb = ft_atoi_int(av[i]);
        new = new_node_a(nb, i - 1);
        new->next = data->pile_a;
        data->pile_a = new;
        data->size_pile_a++;
        i++;
    }
}

void    parsing(t_data *data, char **av)
{
    args_to_pile_a(data, av);
    // check_for_doubles(data);
}