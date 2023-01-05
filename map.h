/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:50:01 by crtorres          #+#    #+#             */
/*   Updated: 2023/01/05 17:55:10 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

/**
 * [Component]
 * The component is astructure element that contains map file.
 * 'p' : player
 * 'e' : exit
 * 'c' : collectible item
 * 'r' : Charizard enemy
 *  */
typedef struct s_compo
{
	int		p;
	int		e;
	int		c;
	int		r;
}			t_compo;

/**
 * `t_map` is a type that contains the number of rows and columns in a map, a 2D
 * array of characters that represent the map, a string that contains the file
 * name, and a `t_compo` type that contains the number of components in the map.
 * @property {int} rows - the number of rows in the map
 * @property {int} cols - The number of columns in the map.
 * @property {char} coord - This is a 2D array that holds the map.
 * @property {char} file - the file name
 * @property {t_compo} cnt - This is a struct that contains the number of each
 * character in the map.
 */
typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coord;
	char	*file;
	t_compo	cnt;
}			t_map;

#endif