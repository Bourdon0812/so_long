/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:13:50 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/09 19:27:31 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	i;
	size_t	i2;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1[i] != '\0')
		join[i2++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		join[i2++] = s2[i++];
	join[i2] = '\0';
	return (join);
}
