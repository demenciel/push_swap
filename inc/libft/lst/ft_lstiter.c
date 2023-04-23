/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:40 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:22:57 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Iterates over the linked list to apply the f function to 
 	each node's content.
 * @param lst Pointer to the head of the linked list
 * @param f The function to be applied to the nodes content
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*new;

	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		new = lst->next;
		lst = new;
	}
}
