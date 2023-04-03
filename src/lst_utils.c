/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:49:10 by acouture          #+#    #+#             */
/*   Updated: 2023/04/03 14:08:56 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pile	*new_node(int data, int index)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	new->data = malloc(sizeof(int));
	*(new->data) = data;
	new->index = malloc(sizeof(int));
	*(new->index) = index;
	new->next = NULL;
	return (new);
}

void	lst_add_b(t_pile **lst, t_pile *new)
{
	t_pile	*node;

	node = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = new;
}

bool	lst_sorted(t_pile **lst)
{
	t_pile	*node;
	t_pile	*check;

	node = *lst;
	check = node->next;
	while (node != NULL && check->next != NULL)
	{
		if (*(node->data) > *(check->data))
			return (false);
		node = node->next;
		check = check->next;
	}
	return (true);
}

t_pile	*lst_last_node(t_pile **lst)
{
	t_pile	*node;

	node = *lst;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	lst_len(t_pile **lst)
{
	t_pile	*node;
	int		len;

	len = 0;
	node = *lst;
	while (node != NULL)
	{
		len++;
		node = node->next;
	}
	return (len);
}
