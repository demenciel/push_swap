/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:30:43 by acouture          #+#    #+#             */
/*   Updated: 2023/03/13 14:25:53 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// MACROS ------------------------------------------------------------------

# define INT_MAX 2147483647
# define INT_MIN (-2147483647 - 1)

// STRUCTURES --------------------------------------------------------------

typedef struct s_push_swap
{
	int	*pile_a;
	int	*pile_b;
	int	size_pile_a;
	int size_pile_b;
}		t_data;

// SORTING --------------------------------------------------------------
void	sorting_under_3(t_data *data);
void	sorting(t_data *data);

// PARSING --------------------------------------------------------------
void	parsing(t_data *data, char **av);
void	args_to_pile_a(t_data *data, char **av);
void	copy_a_to_b(t_data *data, int len);

// UTILS --------------------------------------------------------------
int		ft_atoi_int(char *str);
void	ft_swap(int *a, int *b);
void	*ft_realloc(void *ptr, size_t size);

// COMMANDS --------------------------------------------------------------
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void    swap_swap(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	rotate_a(t_data *data);

#endif