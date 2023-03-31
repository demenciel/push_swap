/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:30:43 by acouture          #+#    #+#             */
/*   Updated: 2023/03/31 12:54:30 by acouture         ###   ########.fr       */
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
	int				*data;
	int				*index;
	bool			checked;
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
void				sorting_big(t_data *data);
void				sorting(t_data *data);
bool				lst_sorted(t_pile **lst);
void				pre_sort_b(t_data *data);
void				sort_a_100(t_data *data);
void				sort_b_half(t_data *data);

// PARSING --------------------------------------------------------------
void				parsing(t_data *data, char **av);
void				args_to_pile_a(t_data *data, char **av);

// PARSING UTILS --------------------------------------------------------------
int					ft_atoi_int(char *s);
void				check_word(char *s);
void				check_fit(char *s);

// UTILS --------------------------------------------------------------
t_pile				*new_node(int data, int index);
t_pile				*lst_last_node(t_pile **lst);
void				lst_add_b(t_pile **lst, t_pile *new);
void				b_to_a(t_data *data);
void				struct_init(t_data *data);
int					find_max(t_pile **lst, int len);
int					find_min(t_pile **lst, int len);
void				data_on_top(t_pile **lst, char pile, int index);
int					lst_len(t_pile **lst);
void				print_pile(t_data *data);
int					avg_of_pile(t_pile **lst, int pile_size);
void				update_indexes(t_pile **lst);

// COMMANDS --------------------------------------------------------------
void				swap(t_pile **lst, char pile, bool print);
void				push_b(t_data *data);
void				push_a(t_data *data);
void				last_to_first(t_pile **lst, char pile, bool print);
void				first_to_last(t_pile **lst, char pile, bool print);

#endif