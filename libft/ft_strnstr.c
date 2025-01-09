/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:08:29 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/09 19:28:31 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			i2 = 0;
			while (i + i2 < len && needle[i2] != '\0'
				&& haystack[i + i2] == needle[i2]
			)
				i2++;
			if (needle[i2] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
