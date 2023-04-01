/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:10:53 by acouture          #+#    #+#             */
/*   Updated: 2023/04/01 09:14:26 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	find_max(t_pile **lst, int len)
{
	t_pile	*node;
	t_pile	*check;
	int		max_data;

	node = *lst;
	if (node->next == NULL)
		ft_error("");
	max_data = *(node->data);
	while (len)
	{
		check = node->next;
		while (check != NULL)
		{
			if (max_data < *(check->data))
				max_data = *(check->data);
			check = check->next;
		}
		node = node->next;
		len--;
	}
	return (max_data);
}

int	find_min(t_pile **lst, int len)
{
	t_pile	*node;
	t_pile	*check;
	int		min_data;

	node = *lst;
	if (node->next == NULL)
		ft_error("");
	min_data = *(node->data);
	while (len)
	{
		check = node->next;
		while (check != NULL)
		{
			if (min_data > *(check->data))
				min_data = *(check->data);
			check = check->next;
		}
		node = node->next;
		len--;
	}
	return (min_data);
}

void	update_indexes(t_pile **lst)
{
	t_pile	*node;
	int		index;

	node = *lst;
	index = 0;
	while (node != NULL)
	{
		*(node->index) = index++;
		node = node->next;
	}
}

void	data_on_top(t_pile **lst, char pile, int data)
{
	t_pile	*node;
	t_pile	*node_index;
	int		steps_to_max;

	node = *lst;
	node_index = NULL;
	steps_to_max = 0;
	if (data == *(node->data))
		return ;
	while (node != NULL)
	{
		if (*(node->data) == data)
		{
			node_index = node;
			break ;
		}
		node = node->next;
		steps_to_max++;
	}
	move_data(lst, pile, *(node_index->index), steps_to_max);
}

void	move_data(t_pile **lst, char pile, int index, int steps_to_max)
{
	int	steps_needed;

	if (index > (lst_len(lst) / 2))
		steps_needed = lst_len(lst) - steps_to_max;
	else
		steps_needed = steps_to_max;
	while (steps_needed)
	{
		if (index > (lst_len(lst) / 2))
			last_to_first(lst, pile, true);
		else
			first_to_last(lst, pile, true);
		steps_needed--;
	}
}
