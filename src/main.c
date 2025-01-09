/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:35:29 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/01/08 21:53:14 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main_loop(t_game *game)
{
	if (game != NULL)
    	return (0);
	return (1);
}

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int	stop_game(t_game *game)
{
	if (game->player.collected_count && game->nb_collectibles)
		if (game->player.collected_count == game->nb_collectibles)
			ft_putstr_fd("win !!\n", 1);
	exit(EXIT_FAILURE);
	return (1);
}

int main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2 || !ft_checkextension(argv[1], ".ber"))
	{
		ft_putstr_fd("Error\nVeuillez saisir une map .ber", 2);
		return (-1);	
	}
	if (!init_map(&game, argv[1]))
	{
		stop_game(&game);
		return (-1);	
	}
	print_map(game.map.map);
	if (!init_render(&game))
	{
		stop_game(&game);
		return (-1);	
	}
	return (0);
}

/*
int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "Fenetre nul");

    mlx_hook(window, 17, 0, close_window, NULL);

    mlx_loop(mlx);

    return (0);
}*/