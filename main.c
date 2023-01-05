/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:13:30 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/01/05 17:13:01 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# define CHARMANDER			100
/* # define charmander_pos_x	100
# define charmander_pos_y	100 */

/* typedef struct s_move {
	void	*up;
	void	*right;
	void	*left;
	void	*down;
}				t_move; */

/* int	keypress(int keycode, t_game *game)
{
	//printf("%d\n", keycode);
	return (0);
} */

int	redcross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

/* int	detectmouse(int x, int y, t_game *game)
{
	(void) game;
	printf("x = %d y = %d\n", x, y);
	return (0);
} */


int	main(void)
{
	t_game	game;
	
	launch_game(&game);
	//mlx_hook(game.win, 4, 1L<<1, keypress, &game);
	//mlx_hook(game.win, 4, 1L<<1, move, &game);
	//mlx_hook(game.win, 6, 0, detectmouse, &game);
	//mlx_loop_hook(game.mlx, render_next_frame, up);
	mlx_hook(game.win, KEY_EXIT, 0, redcross, &game);
	// mlx_key_hook(game.win, keypress, &game);				/* hook para movimiento segun suelta la tecla */
	mlx_hook(game.win, KEY_PRESS, 0, &keypress, &game);		/* hook para movimiento al pulsar o mantener tecla */
	//mlx_key_hook(game.win, move, &game);
	mlx_loop(game.mlx);
}
