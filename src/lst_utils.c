/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:49:10 by acouture          #+#    #+#             */
/*   Updated: 2023/03/19 07:57:10 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pile	*new_node(int data, int index)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	new->data = data;
    new->index = index;
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

void    lst_sorted(t_pile **lst)
{
    t_pile *node;
    t_pile *check;
    int flag;

    node = *lst;
    check = node->next;
    flag = 1;
    while (node->data < check->data && check->next != NULL)
    {
        check = check->next;
        flag = 0;
    }
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