/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:22:22 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 15:20:03 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_map(char **map)
{
	int	row;

	row = 0;
	while (map[row] != NULL)
	{
		ft_putstr_fd(map[row], 1);
		ft_putstr_fd("\n", 1);
		row++;
	}
}

char	**copy_map(char **map)
{
	int		rows;
	int		i;
	char	**copy;

	rows = ft_nbrow(map);
	copy = malloc((rows + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_map(char **map)
{
	int	row;

	row = 0;
	while (map[row])
	{
		free(map[row]);
		row++;
	}
	free(map);
}
