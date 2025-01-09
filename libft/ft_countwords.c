/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:15:47 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/06 14:49:25 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(const char *s, const char *sep)
{
	size_t	wc;
	size_t	i;
	int		in_word;

	in_word = 0;
	wc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isinset(s[i], sep))
			in_word = 0;
		else
		{
			if (!in_word)
				wc++;
			in_word = 1;
		}
		i++;
	}
	return (wc);
}
