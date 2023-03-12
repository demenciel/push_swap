/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:30:43 by acouture          #+#    #+#             */
/*   Updated: 2023/03/12 15:52:57 by acouture         ###   ########.fr       */
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
# define INT_MIN -2147483647

// STRUCTURES --------------------------------------------------------------

typedef struct s_push_swap
{
    int       *pile_a;
}              t_data;


// PARSING --------------------------------------------------------------
void    parsing(t_data *data, char **av);
void    args_to_pile_a(t_data *data, char **av);



#endif