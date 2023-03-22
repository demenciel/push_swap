/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:10:53 by acouture          #+#    #+#             */
/*   Updated: 2023/03/22 15:06:29 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	find_max(t_pile **lst)
{
	t_pile	*node;
	t_pile	*check;
	int		max_index;
	int		max_data;

	node = *lst;
	if (node->next == NULL)
		ft_error("Max error");
	max_index = node->index;
	max_data = node->data;
	while (node != NULL)
	{
		check = node->next;
		while (check != NULL)
		{
			if (max_data < check->data)
			{
				max_index = check->index;
				max_data = check->data;
			}
			check = check->next;
		}
		node = node->next;
	}
	return (max_index);
}

int	find_min(t_pile **lst, int len)
{
	t_pile	*node;
	t_pile	*check;
	int		min_data;

	node = *lst;
	if (node->next == NULL)
		ft_error("Min error");
	min_data = node->data;
	while (len)
	{
		check = node->next;
		while (check != NULL)
		{
			if (min_data > check->data)
				min_data = check->data;
			check = check->next;
		}
		node = node->next;
		len--;
	}
	return (min_data);
}

void	data_on_top(t_pile **lst, char pile, int data)
{
	t_pile *node;
	t_pile *node_index;
	int steps_to_max;
	int steps_needed;

	node = *lst;
	node_index = NULL;
	steps_to_max = 0;
	if (data == node->data)
		return ;
	while (node != NULL)
	{
		if (node->data == data)
		{
			node_index = node;
			break ;
		}
		node = node->next;
		steps_to_max++;
	}
	if (node_index->index > (lst_len(lst) / 2))
		steps_needed = lst_len(lst) - steps_to_max;
	else
		steps_needed = steps_to_max;
	while (steps_needed)
	{
		if (node_index->index > (lst_len(lst) / 2))
			last_to_first(lst, pile, true);
		else
			first_to_last(lst, pile, true);
		steps_needed--;
	}
}

void	print_pile(t_data *data)
{
	t_pile	*pa;
	t_pile	*pb;

	pa = *data->pile_a;
	ft_printf("\n");
	while (pa != NULL)
	{
		ft_printf("%d-%d\n", pa->data, pa->index);
		pa = pa->next;
	}
	ft_printf("\n");
	pb = *data->pile_b;
	while (pb != NULL)
	{
		ft_printf("%d\n", pb->data, pb->index);
		pb = pb->next;
	}
}

// int	find_min(t_pile **lst, int index)
// {
// 	t_pile	*node;
// 	t_pile	*check;
// 	int		min_index;
// 	int		min_data;

// 	node = *lst;
// 	if (node->next == NULL)
// 		ft_error("Min error");
// 	min_index = node->index;
// 	min_data = node->data;
// 	while (node->index < index)
// 	{
// 		check = node->next;
// 		while (check != NULL)
// 		{
// 			if (min_data > check->data)
// 			{
// 				min_index = check->index;
// 				min_data = check->data;
// 			}
// 			check = check->next;
// 		}
// 		node = node->next;
// 	}
// 	return (min_data);
// }
