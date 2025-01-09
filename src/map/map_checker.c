/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:17:10 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 16:22:35 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	map_check_player(char **map, t_game *game)
{
	int			nb_player;
	int			row;
	int			col;

	row = 0;
	nb_player = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
			{
				nb_player++;
				set_player(game, col, row);
			}
			col++;
		}
		row++;
	}
	if (nb_player != 1)
		return (0);
	return (1);
}

int	map_check_charset(char **map)
{
	char	*charset;
	int		row;
	int		col;

	charset = "01CEP";
	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (!ft_isinset(map[row][col], charset))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	map_check_wall(char **map)
{
	int	i;
	int	lastrow;
	int	lastcol;

	i = -1;
	lastrow = ft_nbrow(map) - 1;
	lastcol = ft_strlen(map[0]) - 1;
	while (map[0][++i] != '\0')
		if (map[0][i] != '1')
			return (0);
	i = -1;
	while (map[lastrow][++i])
		if (map[lastrow][i] != '1')
			return (0);
	i = 0;
	while (++i != lastrow)
		if (map[i][0] != '1' || map[i][lastcol] != '1')
			return (0);
	return (1);
}

int	map_is_rectangle(char **map)
{
	int	ref_length;
	int	row;
	int	i;

	ref_length = ft_strlen(map[0]);
	row = 0;
	while (map[row] != NULL)
	{
		i = 0;
		while (map[row][i] != '\0')
			i++;
		if (i != ref_length)
			return (0);
		row++;
	}
	return (1);
}

int	map_is_valid(t_game *game)
{
	if (!map_is_rectangle(game->map.map))
	{
		ft_putstr_fd("Error\nla map n'est pas un rectangle", 1);
		return (0);
	}
	if (!map_check_charset(game->map.map))
	{
		ft_putstr_fd("Error\nune tile n'existe pas", 1);
		return (0);
	}
	if (!map_check_wall(game->map.map))
	{
		ft_putstr_fd("Error\nla map n'est pas entoure de mur", 1);
		return (0);
	}
	return (map_is_valid2(game));
}
