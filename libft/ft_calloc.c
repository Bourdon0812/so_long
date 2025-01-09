/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:59:39 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/06 16:16:38 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (size != 0 && count * size / size != count)
		return (NULL);
	alloc = (void *)malloc(count * size);
	if (alloc == NULL)
		return (NULL);
	return (ft_memset(alloc, 0, count * size));
}
