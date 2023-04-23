/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:40:33 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:05:28 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the parameter is ascii
 * @param c Character to be checked
 * @return 1 if true, 0 if false
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
