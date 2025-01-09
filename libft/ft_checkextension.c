/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkextension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:05 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/12/02 16:28:43 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_checkextension(char *file, char *ext)
{
	int	file_len;
	int	ext_len;

	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (ext_len > file_len)
		return (0);
	file += file_len - ext_len;
	while (*file && *ext)
	{
		if (*file != *ext)
			return (0);
		file++;
		ext++;
	}
	return (1);
}
