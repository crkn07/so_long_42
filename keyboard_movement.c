/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:46:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/01/05 14:47:21 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "keycode.h"
# define SLIME			100

typedef struct	s_game {
	void	*mlx;
	void	*win;
	int		slime_pos_x;
	int		slime_pos_y;
}				t_game;

typedef struct i_param {
	void	*img;
	void	*negro;
	int		img_width;
	int		img_height;
}				t_param;

int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_SCAPE)
		exit(0);
	t_param	img;
	img.img = mlx_xpm_file_to_image (game->mlx, "/Users/crtorres/Desktop/so_long_conjunto/so_long/charmander.xpm", &img.img_width, &img.img_height);
	img.negro = mlx_xpm_file_to_image (game->mlx, "/Users/crtorres/Desktop/so_long_conjunto/so_long/negro.xpm", &img.img_width, &img.img_height);
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		int i = 0;
		while (i)
		{
			int c = 1, d = 1;
   			for ( c = 1 ; c <= 30767 ; c++ )
       			for ( d = 1 ; d <= 30767 ; d++ )
       	{}}
		mlx_put_image_to_window(game->mlx, game->win, img.negro, game->slime_pos_x, game->slime_pos_y);
		mlx_put_image_to_window(game->mlx, game->win, img.img, game->slime_pos_x, game->slime_pos_y - SLIME);
		game->slime_pos_y -= SLIME;
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		mlx_put_image_to_window(game->mlx, game->win, img.negro, game->slime_pos_x, game->slime_pos_y);
		mlx_put_image_to_window(game->mlx, game->win, img.img, game->slime_pos_x, game->slime_pos_y + SLIME);
		game->slime_pos_y = game->slime_pos_y + SLIME;
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->win, img.negro, game->slime_pos_x, game->slime_pos_y);
		mlx_put_image_to_window(game->mlx, game->win, img.img, game->slime_pos_x - SLIME, game->slime_pos_y);
		game->slime_pos_x = game->slime_pos_x - SLIME;
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->win, img.negro, game->slime_pos_x, game->slime_pos_y);
		mlx_put_image_to_window(game->mlx, game->win, img.img, game->slime_pos_x + SLIME, game->slime_pos_y);
		game->slime_pos_x = game->slime_pos_x + SLIME;
	}
	return (0);
}