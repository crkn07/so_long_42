/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:00:52 by crtorres          #+#    #+#             */
/*   Updated: 2023/01/05 17:55:15 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_dir(t_game *game)
{
	game->coord_dir[NONE] = (t_coord){0, 0};
	game->coord_dir[NORTH] = (t_coord){0, -1};
	game->coord_dir[SOUTH] = (t_coord){0, 1};
	game->coord_dir[WEST] = (t_coord){-1, 0};
	game->coord_dir[EAST] = (t_coord){1, 0};
}
