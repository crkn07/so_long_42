/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:55 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/14 00:37:40 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

/**
 * 			col 0	col 1
 * row 0	[  ]	[  ]
 * row 1	[  ]	[  ]
 */

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		error_message("File open fail\n");
	return (fd);
}

void	count_max_rows_cols(t_game *game, int fd)
{
	int		tmp_cols;
	char	c;

	game->maps.rows = 0;
	game->maps.cols = 0;
	tmp_cols = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (game->maps.cols < tmp_cols)
			game->maps.cols = tmp_cols;
		if (c == '\n')
		{
			game->maps.rows++;
			tmp_cols = 0;
		}
		else
			tmp_cols++;
	}
}

void	map_malloc(t_game *game, int fd)
{
	int	i;

	count_max_rows_cols(game, fd);
	game->maps.coord = (char **)malloc(sizeof(char *) * (game->maps.rows));
	i = 0;
	while (i < game->maps.rows)
	{
		game->maps.coord[i] = (char *)malloc(sizeof(char) * (game->maps.cols));
		i++;
	}
}

void	map_load(t_game *game, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open_file(filename);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (map_rect(game, ft_strlen(line)) == FALSE)
			error_message("Map file is not rectangular.\n");
		j = 0;
		while (j < game->maps.cols)
		{
			if (check_comp(line[j]) == TRUE)
				game->maps.coord[i][j] = line[j];
			else
				error_message("Invalid components found in map file.");
			j++;
		}
		i++;
		free(line);
	}
	free(line);
	close(fd);
}

void	file_read(t_game *game, char *filename)
{
	int		fd;

	check_extension(filename, MAP_EXT);
	fd = open_file(filename);
	map_malloc(game, fd);
	close(fd);
	map_load(game, filename);
	if (fill_walled(game->maps) == FALSE)
		error_message("Map is not walled.\n");
	draw_comp_by_coord(game);
}