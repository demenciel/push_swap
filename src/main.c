/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:20:12 by acouture          #+#    #+#             */
/*   Updated: 2023/03/13 14:22:40 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (ac < 2)
        ft_error("Not enough arguments");
    else
    {
        parsing(data, av);
        sorting(data);
    }
    free(data);
    return (0);
}