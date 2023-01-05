/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:55:40 by crtorres          #+#    #+#             */
/*   Updated: 2023/01/05 18:10:14 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_window(t_game *game)
{
	int	width;
	int	height;
	
	game->mlx = mlx_init();
	width = 1920;
	height = 1080;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

void	launch_img(t_game *game)
{
	t_param img;
	game->charmander_pos_x = 100;
	game->charmander_pos_y = 100;
	img.img = mlx_xpm_file_to_image (game->mlx, "/Users/crtorres/Desktop/so_long_conjunto/so_long/charmander.xpm", &img.img_width, &img.img_height);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 100, 100);
}

/**
 * It initializes the
 * directions
 * 
 * @param game the game struct
 */
void	init_dir(t_game *game)
{
	game->coord_dir[NONE] = (t_coord){0, 0};
	game->coord_dir[NORTH] = (t_coord){0, -1};
	game->coord_dir[SOUTH] = (t_coord){0, 1};
	game->coord_dir[WEST] = (t_coord){-1, 0};
	game->coord_dir[EAST] = (t_coord){1, 0};
}


void	launch_game(t_game *game)
{
	launch_window(game);
	init_dir(game);
	launch_img(game);
}
