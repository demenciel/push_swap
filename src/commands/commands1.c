/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:19:26 by acouture          #+#    #+#             */
/*   Updated: 2023/03/29 09:18:42 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_pile **lst, char pile, bool print)
{
	t_pile	*first_node;
	t_pile	*second_node;

	first_node = *lst;
	if (first_node == NULL || first_node->next == NULL)
		return ;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*lst = second_node;
	if (print == true)
		ft_printf("s%c\n", pile);
}

void	swap_swap(t_pile **lst_a, t_pile **lst_b)
{
	swap(lst_a, 'a', false);
	swap(lst_b, 'b', false);
	ft_printf("ss\n");
}

void	push_b(t_data *data)
{
	t_pile	*node;
	t_pile	*new_head_a;
	t_pile	*new_node_b;

	node = *data->pile_a;
	new_head_a = node->next;
	new_node_b = new_node(node->data, data->size_pile_a + 1);
	new_node_b->next = *data->pile_b;
	*data->pile_b = new_node_b;
	*data->pile_a = new_head_a;
	data->size_pile_a--;
	data->size_pile_b++;
	update_indexes(data->pile_b);
	update_indexes(data->pile_a);
	ft_printf("pb\n");
}

void	push_a(t_data *data)
{
	t_pile	*node;
	t_pile	*new_head_b;
	t_pile	*new_node_a;

	if ((*data->pile_b) == NULL)
		return ;
	node = *data->pile_b;
	new_head_b = node->next;
	new_node_a = new_node(node->data, node->index);
	new_node_a->next = *data->pile_a;
	*data->pile_a = new_node_a;
	*data->pile_b = new_head_b;
	data->size_pile_a++;
	data->size_pile_b--;
	update_indexes(data->pile_b);
	update_indexes(data->pile_a);
	ft_printf("pa\n");
}
