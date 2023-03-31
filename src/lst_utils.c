/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:49:10 by acouture          #+#    #+#             */
/*   Updated: 2023/03/31 13:04:34 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// t_pile	*new_node(int data, int index)
// {
// 	t_pile	*new;
    
// 	new = (t_pile *)malloc(sizeof(t_pile));
//     if (!new)
//         ft_error("Error");
// 	new->data = data;
//     new->index = index;
// 	new->next = NULL;
// 	return (new);
// }

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

void    lst_add_b(t_pile **lst, t_pile *new)
{
    t_pile *node;

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

bool lst_sorted(t_pile **lst)
{
    t_pile *node;
    
    node = *lst;
    while (node != NULL && node->next != NULL)
    {
        if (node->data > node->next->data)
            return false;
        node = node->next;
    }
    return true;
}

t_pile  *lst_last_node(t_pile **lst)
{
    t_pile *node;

    node = *lst;
    while (node->next != NULL)
        node = node->next;
    return (node);
}

int lst_len(t_pile **lst)
{
    t_pile *node;
    int len;

    len = 0;
    node = *lst;
    while (node != NULL)
    {
        len++;
        node = node->next;
    }
    return (len);
}