/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:17:52 by acouture          #+#    #+#             */
/*   Updated: 2023/03/29 09:18:10 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	median_of_pile(t_pile **lst, int pile_size)
{
	t_pile	*slow;
	t_pile	*fast;
	int		count;
	int		sum;

	slow = *lst;
	fast = *lst;
	count = 0;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		count++;
	}
	if (pile_size % 2 == 0)
	{
		sum = slow->data + slow->next->data;
		return (sum / 2);
	}
	else
		return (slow->data);
}

int	avg_of_pile(t_pile **lst, int pile_size)
{
	int		total;
	int		avg;
	t_pile	*node;

	total = 0;
	avg = 0;
	node = *lst;
	while (node != NULL)
	{
		total += node->data;
		node = node->next;
	}
	avg = total / pile_size;
	return (avg);
}