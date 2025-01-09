/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:26:06 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 14:02:24 by ilbonnev         ###   ########.fr       */
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
			if (map[row][col] == 'E')
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

void	flood_fill(char **map, int x, int y, int rows, int cols)
{
	if (x < 0 || x >= cols || y < 0 || y >= rows || map[y][x] == '1' ||
		map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, rows, cols);
	flood_fill(map, x - 1, y, rows, cols);
	flood_fill(map, x, y + 1, rows, cols);
	flood_fill(map, x, y - 1, rows, cols);
}

int	check_accessible(char **map, t_game *game)
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
	int		rows;
	int		cols;
	char	**map_copy;

	rows = ft_nbrow(game->map.map);
	cols = ft_strlen(game->map.map[0]);
	map_copy = copy_map(game->map.map);
	if (!map_copy)
	{
		ft_putstr_fd("Error\nÉchec de la copie de la carte\n", 2);
		return (0);
	}
	flood_fill(map_copy, game->player.pos.x, game->player.pos.y, rows, cols);
	if (!check_accessible(map_copy, game))
	{
		free_map(map_copy);
		ft_putstr_fd("Error\nCollectibles ou sortie inaccessibles\n", 2);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
