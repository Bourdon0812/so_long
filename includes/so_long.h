/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:37 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/12/20 00:01:34 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ESC 65307
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ESC 65307
# endif

# include "../minilibx/mlx.h"

# include <stdlib.h>
# include <fcntl.h> //open
# include <stdio.h> //perror

# include "game.h"
# include "map.h"
# include "rendering.h"

# include "../libft/libft.h"

#endif