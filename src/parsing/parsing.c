/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/04/01 09:20:54 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	check_for_doubles(t_data *data)
{
	t_pile	*index;
	t_pile	*check;

	check = *data->pile_a;
	if (check->next == NULL)
		return ;
	while (check != NULL)
	{
		index = check->next;
		while (index != NULL)
		{
			if (*(check->data) == *(index->data))
				ft_error("");
			index = index->next;
		}
		check = check->next;
	}
}

void	args_to_pile_a(t_data *data, char **av)
{
	int		i;
	int		nb;
	int		index;
	t_pile	*new;

	i = 1;
	index = 0;
	while (av[i])
	{
		nb = ft_atoi_int(av[i]);
		new = new_node(nb, index);
		lst_add_b(data->pile_a, new);
		data->size_pile_a++;
		i++;
		index++;
	}
	data->size_start_pile = data->size_pile_a;
}

void	parsing(t_data *data, char **av)
{
	args_to_pile_a(data, av);
	check_for_doubles(data);
}
