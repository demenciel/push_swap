/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:31:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/13 10:00:23 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void    sorting_under_3(t_data *data)
{
    int a;
    int b;
    int c;
    a = data->pile_a[0];
    b = data->pile_a[1];
    c = data->pile_a[2];
    if (a > b)
        ft_swap(a, b);
    if (b > c)
        ft_swap(a, b);
    
}

void    sorting(t_data *data)
{
    sorting_under_3(data);
}