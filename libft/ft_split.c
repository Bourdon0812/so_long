/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:13:01 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/09 22:37:58 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeall(char **split, size_t k)
{
	size_t	i;

	i = 0;
	while (i != k)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	addword(char **split, char *word, size_t *k)
	{
	if (word == NULL)
	{
		freeall(split, *k);
		return (0);
	}
	split[*k] = word;
	*k = *k + 1;
	return (1);
}

static size_t	countwords(const char *s, const char sep)
{
	size_t	wc;
	size_t	i;
	int		in_word;

	in_word = 0;
	wc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == sep)
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

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	k;
	size_t	start;
	size_t	end;

	split = (char **)malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (split == NULL)
		return (NULL);
	start = 0;
	k = 0;
	while (s[start] != '\0')
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		if (end > start && !addword(split, ft_getword(s, start, end), &k))
			return (NULL);
		start = end;
	}
	split[k] = NULL;
	return (split);
}
