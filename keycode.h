/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:01:46 by crtorres          #+#    #+#             */
/*   Updated: 2023/01/05 14:35:09 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

/* code button to close in the RED cross on the window frame */
# define KEY_EXIT		17
/* hold down a key */
# define KEY_PRESS		2
/* code button to close on the 'esc' button */
# define KEY_SCAPE		53
# define KEY_RETURN		36
/* code button to reset game on the 'R' button */
# define KEY_RESET		15
/* button codes to move the character */
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

/* A function prototype for the keypress function. */
typedef struct s_game	t_game;

int		keypress(int key_code, t_game *game);

#endif