/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:34:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/08 21:22:21 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

int	get_map_size(char *mappath, t_game *game)
{
	int		fd;
	int		len;
	char	c;
	
	len = 0;
	fd = open(mappath, O_RDONLY);
	if (fd < 0)
		stop_game(game);
	while (read(fd, &c, 1) > 0)
		len++;
	close(fd);
	return (len);
}

char	*map_to_str(char *mappath, t_game *game)
{
	char	*str;
	int		fd;
	int		i;
	
	str = (char *)malloc(sizeof(char) * (get_map_size(mappath, game) + 1));
	if (str == NULL)
		return (NULL);
	fd = open(mappath, O_RDONLY);
	if (fd < 0)
	{
		return (NULL);
		free(str);
	}
	i = 0;
	while (read(fd, &str[i], 1) > 0)
		i++;
	str[i] = '\0';
	return (str);
}

int	init_map(t_game *game, char *mapname)
{
	char	*mapstr;
	
	game->map.path = ft_strcat("resources/maps/", mapname);
	mapstr = map_to_str(game->map.path, game);
	if (mapstr == NULL)
		return (0);
	game->map.map = ft_split(mapstr, '\n');
	free(mapstr);
	if (game->map.map == NULL || !map_is_valid(game))
		return (0);
	game->map.nbrow = ft_nbrow(game->map.map);
	game->map.nbcol = ft_strlen(game->map.map[0]);
	return (1);
}