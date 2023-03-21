/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:30:43 by acouture          #+#    #+#             */
/*   Updated: 2023/03/21 14:23:50 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// MACROS ------------------------------------------------------------------

# define INT_MAX 2147483647
# define INT_MIN (-2147483647 - 1)
# define GREEN "\033[0;92m"

// STRUCTURES --------------------------------------------------------------

typedef struct s_pile
{
	int				data;
	int				index;
	struct s_pile	*next;
}					t_pile;

typedef struct s_push_swap
{
	t_pile			**pile_a;
	t_pile			**pile_b;
	int				size_pile_a;
	int				size_start_pile;
	int				size_pile_b;
}					t_data;

// SORTING --------------------------------------------------------------
void				sorting_3(t_data *data);
void				sorting_4(t_data *data);
void				sorting_5(t_data *data);
void				sorting_100(t_data *data);
void				sorting(t_data *data);
void				lst_sorted(t_pile **lst);

// PARSING --------------------------------------------------------------
void				parsing(t_data *data, char **av);
void				args_to_pile_a(t_data *data, char **av);

// PARSING UTILS --------------------------------------------------------------
int					ft_atoi_int(char *s);
void				check_word(char *s);
void				check_fit(char *s);

// UTILS --------------------------------------------------------------
void				ft_swap(int *a, int *b);
void				struct_init(t_data *data);
t_pile				*new_node(int data, int index);
void				lst_add_b(t_pile **lst, t_pile *new);
t_pile				*lst_last_node(t_pile **lst);
void				copy_a_to_b(t_data *data);
int					find_max(t_pile **lst);
int					lst_len(t_pile **lst);
int					find_min(t_pile **lst, int index);
void				data_on_top(t_pile **lst, char pile, int index);
void				print_pile(t_data *data);

// COMMANDS --------------------------------------------------------------
void				swap(t_pile **lst, char pile, bool print);
void				push_b(t_data *data);
void				push_a(t_data *data);
void				last_to_first(t_pile **lst, char pile, bool print);
void				first_to_last(t_pile **lst, char pile, bool print);

#endif