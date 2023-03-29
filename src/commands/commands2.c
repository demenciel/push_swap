/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:02:56 by acouture          #+#    #+#             */
/*   Updated: 2023/03/29 09:18:39 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	first_to_last(t_pile **lst, char pile, bool print)
{
	t_pile	*last_node;
	t_pile	*second_node;
	t_pile	*first_node;

	if (*lst == NULL || (*lst)->next == NULL)
		ft_error("empty list, can't make move");
	first_node = *lst;
	second_node = first_node->next;
	last_node = *lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	*lst = second_node;
	update_indexes(lst);
	if (print)
		ft_printf("r%c\n", pile);
}

void	last_to_first(t_pile **lst, char pile, bool print)
{
	t_pile	*first_node;
	t_pile	*second_to_last_node;
	t_pile	*last_node;

	if (*lst == NULL || (*lst)->next == NULL)
		ft_error("empty list, can't make move");
	first_node = *lst;
	second_to_last_node = first_node;
	last_node = first_node->next;
	while (last_node->next != NULL)
	{
		second_to_last_node = last_node;
		last_node = last_node->next;
	}
	second_to_last_node->next = NULL;
	last_node->next = first_node;
	*lst = last_node;
	update_indexes(lst);
	if (print)
		ft_printf("rr%c\n", pile);
}
