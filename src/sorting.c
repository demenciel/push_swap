/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:31:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/16 14:28:54 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	    sorting_under_3(t_data *data)
{
    t_pile *top;
    t_pile *mid;
    t_pile *bottom;

    top = *data->pile_a;
    mid = top->next;
    bottom = mid->next;
    if (top->data > mid->data && top->data < bottom->data)
        swap_a(data);
    if (top->data > mid->data && mid->data > bottom->data)
    {
        first_to_last_a(data);
        swap_a(data);
    }
    if (top->data > bottom->data && mid->data < bottom->data)
        first_to_last_a(data);
    if (top->data < bottom->data && mid->data > bottom->data)
    {
        swap_a(data);
        first_to_last_a(data);
    }
    if (top->data < mid->data && top->data > bottom->data)
        last_to_first_a(data);
    lst_sorted(data->pile_a);
}

void	sorting(t_data *data)
{
    if (data->size_pile_a <= 3)
        sorting_under_3(data);
	// t_pile *pa;

	// pa = *data->pile_a;
	// while (pa != NULL)
	// {
	// 	ft_printf("%d\n", pa->data);
	// 	pa = pa->next;
	// }
    // ft_printf("%d\n", lst_sorted(data->pile_a));
}