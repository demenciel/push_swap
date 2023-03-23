/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:31:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/23 10:17:56 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sorting_5(t_data *data)
{
	t_pile **lst;
	int min;
	int new_min;

	lst = data->pile_a;
	min = find_min(lst, 5);
	data_on_top(lst, 'a', min);
	push_b(data);
	new_min = find_min(lst, 4);
	data_on_top(lst, 'a', new_min);
	push_b(data);
	sorting_3(data);
	push_a(data);
	push_a(data);
}

void	sorting_4(t_data *data)
{
	int min;

	min = find_min(data->pile_a, 4);
	data_on_top(data->pile_a, 'a', min);
	push_b(data);
	sorting_3(data);
	push_a(data);
}

void	sorting_3(t_data *data)
{
	t_pile	*top;
	t_pile	*mid;
	t_pile	*bottom;

	top = *data->pile_a;
	mid = top->next;
	bottom = mid->next;
	if (top->data > mid->data && top->data < bottom->data)
		swap(data->pile_a, 'a', true);
	if (top->data > mid->data && mid->data > bottom->data)
	{
		first_to_last(data->pile_a, 'a', true);
		swap(data->pile_a, 'a', true);
	}
	if (top->data > bottom->data && mid->data < bottom->data)
		first_to_last(data->pile_a, 'a', true);
	if (top->data < bottom->data && mid->data > bottom->data)
	{
		swap(data->pile_a, 'a', true);
		first_to_last(data->pile_a, 'a', true);
	}
	if (top->data < mid->data && top->data > bottom->data)
		last_to_first(data->pile_a, 'a', true);
}

void	sorting(t_data *data)
{
	if (data->size_pile_a <= 3)
		sorting_3(data);
	else if (data->size_pile_a == 4)
		sorting_4(data);
	else if (data->size_pile_a == 5)
		sorting_5(data);
	else if (data->size_pile_a <= 100)
		sorting_100(data);
	 
	// print_pile(data);
}

// 3 numbers -> 2 or 3 moves
// 5 numbers ->   <12 moves
// 100 numbers:
//     <700 moves = 5 pts
//     <900 moves = 4 pts
//     <1,100 moves = 3 pts
//     <1,300 moves = 2 pts
//     <1,500 moves = 1 pts
// 500 numbers:
//     <5,500 moves = 5 pts
//     <7,000 moves = 4 pts
//     <8,500 moves = 3 pts
//     <10,000 moves = 2 pts
//     <11,500 moves = 1 pts