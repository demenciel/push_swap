/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:20:12 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 09:08:07 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    struct_init(t_data *data)
{
    data->pile_a = NULL;
    data->pile_b = NULL;
    data->size_pile_a = 0;
    data->size_pile_b = 0;
}

int main(int ac, char **av)
{
    t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
    if (ac < 2)
        ft_error("Not enough arguments");
    else
    {
        struct_init(data);
        parsing(data, av);
        sorting(data);
    }
    free(data);
    return (0);
}