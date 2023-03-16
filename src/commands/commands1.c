/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:19:26 by acouture          #+#    #+#             */
/*   Updated: 2023/03/16 16:17:31 by acouture         ###   ########.fr       */
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

void	push_b(t_data *data)
{
    t_pile *node;
    t_pile *new_head_a;
    t_pile *new_node_b;

    if ((*data->pile_a) == NULL)
        return ;
    if ((*data->pile_a)->next == NULL)
        return ;
    node = *data->pile_a;    
    new_head_a = node->next;
    new_node_b = new_node(node->data);
    new_node_b->next = *data->pile_b;
    *data->pile_b = new_node_b;
    *data->pile_a = new_head_a;
    ft_printf("pb\n");
}

void	push_a(t_data *data)
{
    t_pile *node;
    t_pile *new_head_b;
    t_pile *new_node_a;

    if ((*data->pile_b) == NULL)
        return ;
    node = *data->pile_b;    
    new_head_b = node->next;
    new_node_a = new_node(node->data);
    new_node_a->next = *data->pile_a;
    *data->pile_a = new_node_a;
    *data->pile_b = new_head_b;
    ft_printf("pa\n");
}
