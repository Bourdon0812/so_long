/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:40:03 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/08 21:42:44 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "map.h"
# include "rendering.h"

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct	s_player
{
	t_vector2	pos;
	int			collected_count;
	int			moov_count;
}	t_player;

typedef struct s_game
{
	t_map		map;
	t_render	render;
	t_player	player;
	int			nb_collectibles;
	t_vector2	exit_pos;
}	t_game;

int 	main_loop(t_game *game);
int		stop_game(t_game *game);

int 	key_press(int keycode, t_game *game);
void	move_player(t_game *game, t_vector2 dxy);

void	set_player(t_game *game, int x, int y);
void	set_exit(t_game *game, int x, int y);

#endif

