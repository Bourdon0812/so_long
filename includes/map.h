/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:40:04 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 14:02:36 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_game t_game;
typedef struct s_vector2 t_vector2;

typedef struct	s_map
{
	char	**map;
	char	*path;
	int		nbcol;
	char	nbrow;
}	t_map;

//parsing
int		get_map_size(char *mappath, t_game *game);
char	*map_to_str(char *mappath, t_game *game);
int		init_map(t_game *game, char *mapname);

//checker2
int		map_check_exit(char **map, t_game *game);
int		map_check_collectibles(char **map, t_game *game);
void	flood_fill(char **map, int x, int y, int rows, int cols);
int		check_accessible(char **map, t_game *game);
int		map_check_path(t_game *game);

//checker1
int		map_check_player(char **map, t_game *game);
int		map_check_charset(char **map);
int		map_check_wall(char **map);
int		map_is_rectangle(char **map);
int		map_is_valid(t_game *game);

//utils
void	print_map(char **map);
char	**copy_map(char **map);
void	free_map(char **map);

#endif