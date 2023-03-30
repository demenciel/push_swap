/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:20:12 by acouture          #+#    #+#             */
/*   Updated: 2023/03/30 16:59:25 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_node(t_pile *node)
{
	if (node)
	{
		free(node->data);
		free(node);
	}
}

void	free_list(t_pile *node)
{
	t_pile	*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free_node(temp);
	}
}

void	free_struct(t_data *data)
{
	free(data->pile_a);
	free(data->pile_b);
	free(data);
}

void	struct_init(t_data *data)
{
	data->pile_a = (t_pile **)malloc(sizeof(t_pile *));
	*data->pile_a = NULL;
	data->pile_b = (t_pile **)malloc(sizeof(t_pile *));
	*data->pile_b = NULL;
	data->size_pile_a = 0;
	data->size_pile_b = 0;
	data->size_start_pile = 0;
}

int	main(int ac, char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (ac < 2)
		ft_error("Not enough arguments");
	else
	{
		struct_init(data);
		parsing(data, av);
		sorting(data);
	}
	lst_sorted(data->pile_a);
	free_list((*data->pile_a));
    free_list((*data->pile_b));
	free_struct(data);
	return (0);
}