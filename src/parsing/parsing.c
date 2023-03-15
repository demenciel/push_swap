/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:45 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 09:02:57 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    check_for_doubles(t_data *data)
{
    t_pile_a *index;
    t_pile_a *check;

    check = data->pile_a;
    while (check != NULL)
    {
        index = check->next;
        while (index != NULL)
        {
            if (check->data == index->data)
                ft_error("Double in list");
            index = index->next;
        }
        check = check->next;
    }
}

void	args_to_pile_a(t_data *data, char **av)
{
	int			i;
	int			nb;
	t_pile_a	*new;

	i = 1;
	while (av[i])
	{
		nb = ft_atoi_int(av[i]);
		new = new_node_a(nb, i - 1);
		new->next = data->pile_a;
		data->pile_a = new;
		data->size_pile_a++;
		i++;
	}
}

void	parsing(t_data *data, char **av)
{
	args_to_pile_a(data, av);
	check_for_doubles(data);
}
