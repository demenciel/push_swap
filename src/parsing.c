/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/03/13 09:37:32 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    check_word(char *s)
{
    int i;

    i = -1;
    while (s[++i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            ft_error(": Not a number");
    }
}

void    check_for_doubles(t_data *data)
{
    int i;
    int j;
    
    i = 0;
    copy_a_to_b(data, data->size_pile_a);
    while (i < data->size_pile_a)
    {
        j = i + 1;
        while (j < data->size_pile_a)
        {
            if (data->pile_a[i] == data->pile_b[j])
                ft_error(": Double");
            j++;
        }
        i++;
    }
    free(data->pile_b);
}

void    args_to_pile_a(t_data *data, char **av)
{
    int nb_args;
    int i;
    long nb;
    
    i = 1;
    nb_args = 1;
    while (av[nb_args])
        ++nb_args;
    data->size_pile_a = nb_args - 1;
    data->pile_a = malloc(sizeof(int) * data->size_pile_a);
    while (i <= data->size_pile_a)
    {
        check_word(av[i]);
        nb = ft_atoi_int(av[i]);
        data->pile_a[i - 1] = (int)nb;
        i++;
    }
}

void    parsing(t_data *data, char **av)
{
    args_to_pile_a(data, av);
    check_for_doubles(data);
}