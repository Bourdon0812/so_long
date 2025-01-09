/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:22:15 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/05 17:44:56 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1
		&& *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i)
	)
		i++;
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
