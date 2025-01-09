/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:49:10 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/08 23:49:35 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if ((unsigned char *)dst == (unsigned char *)src)
		return ((unsigned char *)dst);
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		}
		return (dst);
	}
	while (i != len)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
