/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:19:26 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 10:19:15 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// void	swap_a(t_data *data)
// {
	
// 	ft_printf("sa\n");
// }

// void	swap_b(t_data *data)
// {
	
// 	ft_printf("sb\n");
// }

// void	swap_swap(t_data *data)
// {
// 	int	temp_a;
// 	int	temp_b;

	
// 	ft_printf("ss\n");
// }

// void	push_a(t_data *data)
// {
	    
// }

void	push_b(t_data *data)
{
    t_pile_a *temp;
    
    temp = data->pile_a;
    data->pile_a = data->pile_a->next;
    data->pile_b = new_node_b(temp->next);
    data->pile_b->index = temp->index;
}