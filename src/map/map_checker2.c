/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:26:06 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 21:53:37 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	map_check_exit(char **map, t_game *game)
{
	int			nb_exit;
	int			row;
	int			col;

	row = 0;
	nb_exit = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'E')
			{
				nb_exit++;
				set_exit(game, col, row);
			}
			col++;
		}
		row++;
	}
	if (nb_exit != 1)
		return (0);
	return (1);
}

int	map_check_collectibles(char **map, t_game *game)
{
	int			nb_collectible;
	int			row;
	int			col;

	row = 0;
	nb_collectible = 0;
	game->nb_collectibles = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'C')
			{
				nb_collectible++;
				game->nb_collectibles++;
			}
			col++;
		}
		row++;
	}
	if (nb_collectible < 1)
		return (0);
	return (1);
}

void	flood_fill(char **map, t_vector2 pos, int rows, int cols)
{
	t_vector2	npos;

	if (pos.x < 0 || pos.x >= cols || pos.y < 0 || pos.y >= rows
		|| map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'V')
		return ;
	map[pos.y][pos.x] = 'V';
	npos.x = pos.x + 1;
	npos.y = pos.y;
	flood_fill(map, npos, rows, cols);
	npos.x = pos.x - 1;
	npos.y = pos.y;
	flood_fill(map, npos, rows, cols);
	npos.x = pos.x;
	npos.y = pos.y + 1;
	flood_fill(map, npos, rows, cols);
	npos.x = pos.x;
	npos.y = pos.y - 1;
	flood_fill(map, npos, rows, cols);
}

int	check_accessible(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'C' || map[row][col] == 'E')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	map_check_path(t_game *game)
{
	int			rows;
	int			cols;
	char		**map_copy;
	t_vector2	pos;

	rows = ft_nbrow(game->map.map);
	cols = ft_strlen(game->map.map[0]);
	map_copy = copy_map(game->map.map);
	if (!map_copy)
	{
		ft_putstr_fd("Error\nÉchec de la copie de la carte\n", 2);
		return (0);
	}
	pos.x = game->player.pos.x;
	pos.y = game->player.pos.y;
	flood_fill(map_copy, pos, rows, cols);
	if (!check_accessible(map_copy))
	{
		free_map(map_copy);
		ft_putstr_fd("Error\nCollectibles ou sortie inaccessibles\n", 2);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
