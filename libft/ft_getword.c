/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:38:58 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/06 14:09:15 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy of s, start included but end no included
char	*ft_getword(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}
