/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:17:52 by acouture          #+#    #+#             */
/*   Updated: 2023/03/31 14:54:47 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
		total += *(node->data);
		node = node->next;
	}
	avg = total / pile_size;
	return (avg);
}
