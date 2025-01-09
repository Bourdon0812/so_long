/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:10:08 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 16:19:19 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_tile(t_game *game, char tile, t_vector2 pos)
{
	t_render	*render;
	t_textures	textures;
	void		*img;

	render = &game->render;
	textures = render->textures;
	img = NULL;
	if (tile == '0')
		img = textures.water_texture.img;
	else if (tile == '1')
		img = textures.wall_texture.img;
	else if (tile == 'C')
		img = textures.item_texture.img;
	else if (tile == 'E')
		img = textures.escape_texture.img;
	else if (tile == 'P')
		img = textures.player_texture.img;
	if (img != NULL)
		mlx_put_image_to_window(
			render->mlx, render->window, img,
			pos.x * TILE_SIZE, pos.y * TILE_SIZE
			);
}

void	render_map(t_game *game)
{
	char		**grid;
	t_vector2	pos;

	grid = game->map.map;
	pos.y = 0;
	while (grid[pos.y] != NULL)
	{
		pos.x = 0;
		while (grid[pos.y][pos.x] != '\0')
		{
			render_tile(game, grid[pos.y][pos.x], pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	load_texture(void *mlx, t_texture *texture, char *path, t_game *game)
{
	texture->width = TILE_SIZE;
	texture->height = TILE_SIZE;
	texture->img = mlx_xpm_file_to_image(
			mlx,
			path,
			&texture->width,
			&texture->height);
	if (!texture->img)
	{
		ft_putstr_fd("Error\n Failed to load texture", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		stop_game(game);
	}
}

int	init_render2(t_game *game, t_textures *textures, void *mlx)
{
	load_texture(mlx, &textures->escape_texture, TEXTURE_ESCAPE, game);
	load_texture(mlx, &textures->item_texture, TEXTURE_ITEM, game);
	load_texture(mlx, &textures->player_texture, TEXTURE_PLAYER, game);
	load_texture(mlx, &textures->wall_texture, TEXTURE_WALL, game);
	load_texture(mlx, &textures->water_texture, TEXTURE_WATER, game);
	mlx_loop_hook(game->render.mlx, main_loop, game);
	render_map(game);
	mlx_hook(game->render.window, 2, 1L << 0, key_press, game);
	mlx_hook(game->render.window, 17, 0, stop_game, game);
	mlx_loop(game->render.mlx);
	return (1);
}

int	init_render(t_game *game)
{
	t_textures	*textures;
	void		*mlx;

	textures = &game->render.textures;
	game->render.mlx = mlx_init();
	if (!game->render.mlx)
	{
		ft_putstr_fd("Error\n Failed to initialize mlx\n", 2);
		stop_game(game);
		return (0);
	}
	mlx = game->render.mlx;
	game->render.window = mlx_new_window(game->render.mlx,
			game->map.nbcol * TILE_SIZE,
			game->map.nbrow * TILE_SIZE, WINDOW_NAME);
	return (init_render2(game, textures, mlx));
}
