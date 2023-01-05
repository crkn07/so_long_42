/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:52:41 by crtorres          #+#    #+#             */
/*   Updated: 2023/01/05 16:49:23 by crtorres         ###   ########.fr       */
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
}				t_game;

typedef struct i_param {
	void	*img;
	void	*negro;
	int		img_width;
	int		img_height;
}				t_param;

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

void	launch_game(t_game *game);

#endif