/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:17:17 by tebatsai          #+#    #+#             */
/*   Updated: 2019/10/25 00:34:26 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void			check_press(int key, t_map *all, int i)
{
	check_touch(key, all, i);
	if (key == KEY_ONE)
		all->press->one = i;
	if (key == KEY_TWO)
		all->press->two = i;
	if (key == KEY_THREE)
		all->press->three = i;
	if (key == KEY_FOUR)
		all->press->four = i;
	if (key == KEY_FIVE)
		all->press->five = i;
	if (key == KEY_SPACE)
		all->press->space = i;
}

void			check_touch(int key, t_map *all, int i)
{
	if (key == KEY_LEFT)
		all->press->left = i;
	if (key == KEY_RIGHT)
		all->press->right = i;
	if (key == KEY_DOWN)
		all->press->down = i;
	if (key == KEY_UP)
		all->press->up = i;
	if (key == KEY_PLUS)
		all->press->plus = i;
	if (key == KEY_MINUS)
		all->press->minus = i;
	if (key == KEY_U)
		all->press->u = i;
	if (key == KEY_O)
		all->press->o = i;
	if (key == KEY_I)
		all->press->i = i;
	if (key == KEY_J)
		all->press->j = i;
	if (key == KEY_K)
		all->press->k = i;
	if (key == KEY_L)
		all->press->l = i;
}

int				mouse(int x, int y, t_map *all)
{
	if (all->press->mouse_left)
	{
		all->wd_scale += (x - all->center_map[X]) / ((WIDTH / 4) * all->zoom);
		all->tp_scale += (y - all->center_map[Y]) / ((WIDTH / 4) * all->zoom);
		all->zoom *= 1 / 1.1;
		all->center_map[X] = x;
		all->center_map[Y] = y;
		all->max_iter -= all->max_iter > 0 ? 1 : -1;
		all->x -= 1;
		all->press->mouse_left = 0;
		setting(all);
	}
	if (all->press->mouse_right)
	{
		all->wd_scale += (x - all->center_map[X]) / ((WIDTH / 4) * all->zoom);
		all->tp_scale += (y - all->center_map[Y]) / ((WIDTH / 4) * all->zoom);
		all->zoom *= 1.1;
		all->center_map[X] = x;
		all->center_map[Y] = y;
		all->max_iter += all->max_iter < 150 ? 1 : 0;
		all->x += 1;
		all->press->mouse_right = 0;
		setting(all);
	}
	return (0);
}

int				mousepress(int key, int x, int y, t_map *all)
{
	if (key == MOUSE_LEFT)
	{
		all->press->mouse_left = 1;
		mouse(x, y, all);
	}
	if (key == MOUSE_RIGHT)
	{
		all->press->mouse_right = 1;
		mouse(x, y, all);
	}
	return (0);
}
