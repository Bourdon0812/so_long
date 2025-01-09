/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:15:48 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 14:58:14 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_player(t_game *game, int x, int y)
{
	t_vector2	pos;
	t_player	player;

	pos.x = x;
	pos.y = y;
	player.pos = pos;
	player.collected_count = 0;
	player.moov_count = 0;
	game->player = player;
}

void	set_exit(t_game *game, int x, int y)
{
	t_vector2	pos;

	pos.x = x;
	pos.y = y;
	game->exit_pos = pos;
}
