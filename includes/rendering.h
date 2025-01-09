/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:40:01 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 16:19:42 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# define WINDOW_NAME "so_long [Davgari vs 42]"

# define TEXTURE_ESCAPE	"resources/textures/escape.xpm"
# define TEXTURE_ITEM "resources/textures/item.xpm"
# define TEXTURE_PLAYER "resources/textures/player.xpm"
# define TEXTURE_WALL "resources/textures/wall.xpm"
# define TEXTURE_WATER "resources/textures/water.xpm"

# define TILE_SIZE 64

typedef struct s_game t_game;

typedef struct	s_texture
{
	void	*img;
	int		width;
	int		height;
}	t_texture;


typedef struct	s_textures
{
	t_texture	antagonist_texture;
	t_texture	escape_texture;
	t_texture	item_texture;
	t_texture	player_texture;
	t_texture	wall_texture;
	t_texture	water_texture;
}	t_textures;

typedef struct	s_render
{
	void		*mlx;
	void		*window;
	t_textures	textures;
	
}	t_render;

void	render_tile(t_game *game, char tile, t_vector2 pos);
void	render_map(t_game *game);
void	load_texture(void *mlx, t_texture *texture, char *path, t_game *game);
int		init_render2(t_game *game, t_textures *textures, void *mlx);
int		init_render(t_game *game);

#endif
