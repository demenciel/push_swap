/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:20:12 by acouture          #+#    #+#             */
/*   Updated: 2023/03/16 14:27:56 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    struct_init(t_data *data)
{
    data->pile_a = (t_pile **)malloc(sizeof(t_pile *));
    *data->pile_a = NULL;
    data->pile_b = (t_pile **)malloc(sizeof(t_pile *));
    *data->pile_b = NULL;
}

int main(int ac, char **av)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (ac < 2)
        ft_error("Not enough arguments");
    else
    {
        struct_init(data);
        parsing(data, av);
        sorting(data);
    }
    lst_sorted(data->pile_a);
    free(data);
    return (0);
}