/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/03/12 15:47:35 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    args_to_pile_a(t_data *data, char **av)
{
    int nb_args;
    int i;
    int j;

    j = 0;
    i = 1;
    nb_args = 1;
    while (av[nb_args])
        ++nb_args;
    nb_args -= 1;
    data->pile_a = malloc(sizeof(int) * nb_args);
    while (i <= nb_args)
    {
        data->pile_a[j] = ft_atoi(av[i]);
        if (!ft_atoi(av[i]))
            ft_error("");
        ft_printf("%d\n", data->pile_a[j]);
        i++;
    }
}

void    parsing(t_data *data, char **av)
{
    args_to_pile_a(data, av);
}