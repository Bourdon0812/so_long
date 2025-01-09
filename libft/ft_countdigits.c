/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:40:26 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/06 16:15:01 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// counts the number of digits in nbr (add 1 if nbr negative
size_t	ft_countdigits(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
