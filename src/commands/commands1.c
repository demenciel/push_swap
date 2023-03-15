// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   commands1.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/13 11:19:26 by acouture          #+#    #+#             */
// /*   Updated: 2023/03/13 14:27:28 by acouture         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../inc/push_swap.h"

// void	swap_a(t_data *data)
// {
// 	int	temp;

// 	if ((!data->pile_a) || data->size_pile_a == 1)
// 		return ;
// 	temp = data->pile_a[1];
// 	data->pile_a[1] = data->pile_a[0];
// 	data->pile_a[0] = temp;
// 	ft_printf("sa\n");
// }

// void	swap_b(t_data *data)
// {
// 	int	temp;

// 	if ((!data->pile_b) || data->size_pile_b == 1)
// 		return ;
// 	temp = data->pile_b[1];
// 	data->pile_b[1] = data->pile_b[0];
// 	data->pile_b[0] = temp;
// 	ft_printf("sb\n");
// }

// void	swap_swap(t_data *data)
// {
// 	int	temp_a;
// 	int	temp_b;

// 	if ((!data->pile_a) || data->size_pile_a == 1)
// 		return ;
// 	temp_a = data->pile_a[1];
// 	data->pile_a[1] = data->pile_a[0];
// 	data->pile_a[0] = temp_a;
// 	if (!data->pile_b)
// 		return ;
// 	temp_b = data->pile_b[1];
// 	data->pile_b[1] = data->pile_b[0];
// 	data->pile_b[0] = temp_b;
// 	ft_printf("ss\n");
// }

// void	push_a(t_data *data)
// {
// 	int	i;
// 	int	*new_pile_a;

// 	if (!data->pile_b)
// 		return ;
// 	new_pile_a = ft_realloc(data->pile_a, data->size_pile_a * sizeof(int));
// 	if (!new_pile_a)
// 		return ;
// 	data->pile_a = new_pile_a;
// 	i = data->size_pile_a - 1;
// 	while (i > 0)
// 	{
// 		data->pile_a[i] = data->pile_a[i - 1];
// 		i--;
// 	}
// 	data->pile_a[0] = data->pile_b[0];
    
// }

// void	push_b(t_data *data)
// {
// 	(void)data;
// }