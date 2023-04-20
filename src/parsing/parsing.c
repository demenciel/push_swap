/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/04/20 14:04:38 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_args(t_data *data)
{
	int	i;

	i = 0;
	while (data->args[i])
	{
		free(data->args[i]);
		i++;
	}
	free(data->args);
}

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
			{
				free_list(*data->pile_a);
				free_struct(data);
				write(2, "Error\n", 6);
				exit(1);
			}
			index = index->next;
		}
		check = check->next;
	}
}

void	args_to_pile_a(t_data *data, char **av, int flag)
{
	int		i;
	long	nb;
	int		index;
	t_pile	*new;

	if (flag == 1)
		i = 0;
	else
		i = 1;
	index = 0;
	while (av[i])
	{
		nb = ft_atoi_int(av[i], data);
		check_fit(nb, data);
		new = new_node(nb, index);
		lst_add_b(data->pile_a, new);
		data->size_pile_a++;
		i++;
		index++;
	}
	if (flag == 1)
		free_args(data);
	data->size_start_pile = data->size_pile_a;
}

void	parsing(t_data *data, char **av, int flag)
{
	args_to_pile_a(data, av, flag);
	check_for_doubles(data);
	if (lst_sorted(data->pile_a) == true)
	{
		free_list(*data->pile_a);
		free_struct(data);
		exit(0);
	}
}
