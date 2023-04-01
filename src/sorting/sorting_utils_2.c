/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:17:52 by acouture          #+#    #+#             */
/*   Updated: 2023/04/01 10:15:50 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_pile(t_data *data)
{
	t_pile	*pa;
	t_pile	*pb;

	pa = *data->pile_a;
	while (pa != NULL)
	{
		ft_printf("%d\n", *(pa->data));
		pa = pa->next;
	}
	ft_printf("\n");
	pb = *data->pile_b;
	while (pb != NULL)
	{
		ft_printf("%d\n", *(pb->data));
		pb = pb->next;
	}
}

void	sorting_under_3(t_data *data, int a, int b)
{
	if (a > b)
		swap(data->pile_a, 'a', true);
	else
		return ;
}

int	avg_of_pile(t_pile **lst, int pile_size)
{
	int		total;
	int		avg;
	t_pile	*node;

	total = 0;
	avg = 0;
	node = *lst;
	while (node != NULL)
	{
		total += *(node->data);
		node = node->next;
	}
	avg = total / pile_size;
	return (avg);
}

void	sort_cpy(int *cpy, int size)
{
	int temp;
	int i;
	int y;

	i = 0;
	while (i < size)
	{
		y = i + 1;
		while (y < size)
		{
			if (cpy[i] > cpy[y])
			{
				temp = cpy[y];
				cpy[y] = cpy[i];
				cpy[i] = temp;
			}
			y++;
		}
		i++;
	}
}

int	median(t_pile **lst)
{
	t_pile	*node;
	int		*cpy;
	int 	median;
	int 	i;

	i = 0;
	node = *lst;
	cpy = malloc(sizeof(int) * lst_len(lst));
	while (node != NULL)
	{
		cpy[i] = *(node->data);
		i++;
		node = node->next;
	}
	sort_cpy(cpy, i);
	median = cpy[i / 2];
	free(cpy);
	return (median);
}
