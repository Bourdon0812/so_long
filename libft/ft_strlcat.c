/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:33:47 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/06 14:35:52 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i2;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	i2 = dstlen;
	while (src[i] != '\0' && i < dstsize - dstlen - 1)
	{
		dst[i2] = src[i];
		i++;
		i2++;
	}
	dst[i2] = '\0';
	return (srclen + dstlen);
}
