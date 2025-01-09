/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:45:35 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 17:01:26 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_press(int keycode, t_game *game)
{
	t_vector2	dxy;

	dxy.x = 0;
	dxy.y = 0;
	if (!keycode)
		return (0);
	if (keycode == KEY_W)
		dxy.y = -1;
	else if (keycode == KEY_S)
		dxy.y = 1;
	else if (keycode == KEY_A)
		dxy.x = -1;
	else if (keycode == KEY_D)
		dxy.x = 1;
	else if (keycode == KEY_ESC)
	{
		stop_game(game);
		return (-1);
	}
	else
		return (0);
	move_player(game, dxy);
	return (1);
}

void	move_player(t_game *game, t_vector2 dxy)
{
	t_vector2	new_pos;

	new_pos.x = game->player.pos.x + dxy.x;
	new_pos.y = game->player.pos.y + dxy.y;
	if (game->map.map[new_pos.y][new_pos.x] == '1')
		return ;
	else if (game->map.map[new_pos.y][new_pos.x] == 'C')
		game->player.collected_count++;
	else if (game->map.map[new_pos.y][new_pos.x] == 'E')
	{
		if (game->player.collected_count == game->nb_collectibles)
			stop_game(game);
		else
			return ;
	}
	game->map.map[game->player.pos.y][game->player.pos.x] = '0';
	game->map.map[new_pos.y][new_pos.x] = 'P';
	game->player.pos.x = new_pos.x;
	game->player.pos.y = new_pos.y;
	game->player.moov_count++;
	ft_putnbr_fd(game->player.moov_count, 1);
	ft_putstr_fd("\n", 1);
	render_map(game);
}
