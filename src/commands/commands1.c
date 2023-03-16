/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:19:26 by acouture          #+#    #+#             */
/*   Updated: 2023/03/16 13:20:40 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap_a(t_data *data)
{
	t_pile	*first_node;
	t_pile	*second_node;

	if (*data->pile_a == NULL || (*data->pile_a)->next == NULL)
		return ;
	first_node = *data->pile_a;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*data->pile_a = second_node;
	ft_printf("sa\n");
}

void	swap_b(t_data *data)
{
	t_pile	*first_node;
	t_pile	*second_node;

	if (*data->pile_b == NULL || (*data->pile_b)->next == NULL)
		return ;
	first_node = *data->pile_b;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*data->pile_b = second_node;
	ft_printf("sb\n");
}

// void    swap_swap(t_data *data)
// {
//     int temp;

//     if (!data->pile_b->data)
//         return ;
//     else
//     {
//         temp = data->pile_b->data;
//         data->pile_b->data = data->pile_b->next->data;
//         data->pile_b->next->data = temp;
//     }

//     if (!data->pile_a->data)
//         return ;
//     else
//     {
//         temp = data->pile_a->data;
//         data->pile_a->data = data->pile_a->next->data;
//         data->pile_a->next->data = temp;
//     }
// 	ft_printf("ss\n");
// }

// void	push_b(t_data *data)
// {
//     (void)data;
// }

// void	push_a(t_data *data)
// {
//     t_pile_b *pb;
//     t_pile_a *new;

//     if (!data->pile_b)
//         return ;
//     else
//     {
//         pb = data->pile_b;
//         data->pile_b = data->pile_b->next;
//         data->size_pile_b--;
//         new = new_node_a(pb->data, 0);
//         new->next = data->pile_a;
//         data->size_pile_a++;
//         data->pile_a = new;
//         ft_printf("pa");
//     }
// }
