/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:21:18 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/09 16:23:40 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	map_is_valid2(t_game *game)
{
	if (!map_check_player(game->map.map, game))
	{
		ft_putstr_fd("Error\nplayer invalide", 1);
		return (0);
	}
	if (!map_check_exit(game->map.map, game))
	{
		ft_putstr_fd("Error\nsortie invalide", 1);
		return (0);
	}
	if (!map_check_collectibles(game->map.map, game))
	{
		ft_putstr_fd("Error\nla map n est pas un rectangle", 1);
		return (0);
	}
	if (!map_check_path(game))
	{
		ft_putstr_fd("Error\nla map n est pas un rectangle", 1);
		return (0);
	}
	return (1);
}
