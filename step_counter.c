/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:46:39 by crtorres          #+#    #+#             */
/*   Updated: 2023/01/05 18:24:28 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * `t_flags` is a struct that holds all the flags that are used to control the
 * game.
 * @property {int} collect_all - This is a flag that is set to 1 when the player
 * has collected all the keys.
 * @property {int} held_keys - This is a bitmask that holds the keys that are
 * currently being held down.
 * @property {int} player_walk - This is a flag that is set to 1 when the player is
 * walking.
 * @property {int} enemy_walk - This is a flag that is set to 1 when the enemy is
 * walking.
 * @property {int} step_cnt - This is the number of steps the player has taken.
 * @property {int} game_scene - 0 = main menu, 1 = game, 2 = game over
 */
typedef struct s_flags
{
	int		collect_all;
	int		held_keys;
	int		player_walk;
	int		enemy_walk;
	int		step_cnt;
	int		game_scene;
}			t_flags;


/* This is a macro that is used to define the value of TRUE as 1. */
# define TRUE			1
/* This is a macro that is used to define the value of FALSE as 0. */
# define FALSE			0

static void	print_step_count(t_game *game)
{
	/* Printing the string "Step : " to the standard output. */
	ft_putstr_fd("Step : ", 1);
	/* Printing the step count to the standard output. */
	ft_putnbr_fd(game->player.spr.step, 1);
	/* Printing a new line to the standard output. */
	ft_putstr_fd("\n", 1);
	/* Setting the step count flag to false. */
	game->flag.step_cnt = FALSE;
}