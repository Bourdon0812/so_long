/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:28:39 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/07 14:51:31 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*nstr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isinset(s1[start], set))
		start++;
	while (ft_isinset(s1[end], set) && end > start)
		end--;
	nstr = ft_getword(s1, start, end + 1);
	if (nstr == NULL)
		return (NULL);
	return (nstr);
}
