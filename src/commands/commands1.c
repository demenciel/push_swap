/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:19:26 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 14:53:32 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap_a(t_data *data)
{
    int temp;

    if (!data->pile_a->data)
        return ;
    else
    {
        temp = data->pile_a->data;
        data->pile_a->data = data->pile_a->next->data;
        data->pile_a->next->data = temp;
    }
	ft_printf("sa\n");
}

void	swap_b(t_data *data)
{
	int temp;

    if (!data->pile_b->data)
        return ;
    else
    {
        temp = data->pile_b->data;
        data->pile_b->data = data->pile_b->next->data;
        data->pile_b->next->data = temp;
    }
	ft_printf("sa\n");
}

void    swap_swap(t_data *data)
{
    int temp;

    if (!data->pile_b->data)
        return ;
    else
    {
        temp = data->pile_b->data;
        data->pile_b->data = data->pile_b->next->data;
        data->pile_b->next->data = temp;
    }

    if (!data->pile_a->data)
        return ;
    else
    {
        temp = data->pile_a->data;
        data->pile_a->data = data->pile_a->next->data;
        data->pile_a->next->data = temp;
    }
	ft_printf("ss\n");
}

void	push_b(t_data *data)
{
    t_pile_a *pa;
    t_pile_b *new;

    if (!data->pile_a)
        return ;
    else
    {
        pa = data->pile_a;
        data->pile_a = data->pile_a->next;
        data->size_pile_a--;
        new = new_node_b(pa->data);
        new->index = 0;
        new->next = data->pile_b;
        data->size_pile_b++;
        data->pile_b = new;
        ft_printf("pa");
    }
}

void	push_a(t_data *data)
{
    t_pile_b *pb;
    t_pile_a *new;

    if (!data->pile_b)
        return ;
    else
    {
        pb = data->pile_b;
        data->pile_b = data->pile_b->next;
        data->size_pile_b--;
        new = new_node_a(pb->data, 0);
        new->next = data->pile_a;
        data->size_pile_a++;
        data->pile_a = new;
        ft_printf("pa");
    }
}