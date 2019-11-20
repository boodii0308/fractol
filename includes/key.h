/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:24:42 by tebatsai          #+#    #+#             */
/*   Updated: 2019/10/24 23:00:16 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_FIVE 23
# define KEY_U 32
# define KEY_O 31
# define KEY_I 34
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SPACE 49
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_PLUS 69
# define KEY_MINUS 78
# define MOUSE_LEFT 2
# define MOUSE_RIGHT 1
# define KEY_ESC 53

typedef struct	s_keys
{
	int			space:1;
	int			one:1;
	int			two:1;
	int			three:1;
	int			four:1;
	int			five:1;
	int			left:1;
	int			right:1;
	int			down:1;
	int			up:1;
	int			esc:1;
	int			plus:1;
	int			minus:1;
	int			u:1;
	int			o:1;
	int			i:1;
	int			j:1;
	int			k:1;
	int			l:1;
	int			mouse_left:1;
	int			mouse_right:1;
}				t_keys;
#endif
