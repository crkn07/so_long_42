/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:52:41 by crtorres          #+#    #+#             */
/*   Updated: 2023/01/05 18:50:51 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "keycode.h"
# include "Libft/libft.h"

# define TRUE			1
# define FALSE			0

# define NONE		0
# define SOUTH		1
# define WEST		2
# define NORTH		3
# define EAST		4

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_clst
{
	t_coord			coord;
	int				istouch;
	struct s_clst	*next;
}					t_clst;

typedef struct i_param {
	void	*img;
	void	*mapa;
	int		img_width;
	int		img_height;
}				t_param;

typedef struct s_tile
{
	t_param	t0;
	t_param	t1;
	t_param	tl;
	t_param	tb;
	t_param	ts;
}			t_tile;

typedef struct s_spr
{
	t_param	imgx[5][3];
	int		frame;
	int		frame_max;
	int		step;
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		i;
	int		dir;
	int		move;
}			t_spr;

typedef struct s_player
{
	t_spr	spr;
	int		life;
	int		step;
	int		item;
}			t_player;

/**
 * T_game is a struct that contains a void pointer to the mlx, a void pointer to
 * the window, and two ints for the charmander's position.
 * @property {void} mlx - the pointer to the mlx library
 * @property {void} win - the window that will be displayed
 * @property {int} charmander_pos_x - The x position of the charmander.
 * @property {int} charmander_pos_y - The y position of the charmander.
 */
typedef struct	s_game {
	void		*mlx;
	void		*win;
	int			charmander_pos_x;
	int			charmander_pos_y;
	t_player	player;
	t_coord		coord_dir[5];
}				t_game;



void	launch_game(t_game *game);


#endif