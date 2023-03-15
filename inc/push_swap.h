/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:30:43 by acouture          #+#    #+#             */
/*   Updated: 2023/03/15 07:40:43 by acouture         ###   ########.fr       */
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

typedef struct s_pile_a
{
	int				data;
	int				index;
	struct s_pile_a	*next;
}					t_pile_a;

typedef struct s_pile_b
{
	int				data;
	struct s_pile_b	*next;
}					t_pile_b;

typedef struct s_push_swap
{
	t_pile_a		*pile_a;
	t_pile_b		*pile_b;
	int				size_pile_a;
	int				size_pile_b;
}					t_data;

// SORTING --------------------------------------------------------------
void				sorting_under_3(t_data *data);
void				sorting(t_data *data);

// PARSING --------------------------------------------------------------
void				parsing(t_data *data, char **av);
void				args_to_pile_a(t_data *data, char **av);
void				copy_a_to_b(t_data *data, int len);

// UTILS --------------------------------------------------------------
int					ft_atoi_int(char *str);
void				ft_swap(int *a, int *b);
void				struct_init(t_data *data);
t_pile_a			*new_node_a(int data, int index);

// COMMANDS --------------------------------------------------------------
void				swap_a(t_data *data);
void				swap_b(t_data *data);
void				swap_swap(t_data *data);
void				push_a(t_data *data);
void				push_b(t_data *data);
void				rotate_a(t_data *data);

#endif