/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:52:52 by tebatsai          #+#    #+#             */
/*   Updated: 2019/10/25 00:26:41 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void			color(t_map *all)
{
	if (all->press->i)
	{
		all->x += 1;
	}
	else if (all->press->k)
	{
		all->x -= 1;
	}
}

int				rotation(t_map *all)
{
	zoom(all);
	move(all);
	color(all);
	basic(all);
	setting(all);
	return (0);
}

void			zoom(t_map *all)
{
	if (all->press->plus)
	{
		all->zoom /= 0.05;
		all->max_iter += 1;
		all->tp_scale += 0.5;
	}
	else if (all->press->minus)
	{
		all->zoom *= 0.05;
		all->max_iter -= 1;
		all->tp_scale -= 0.5;
	}
	if (all->press->u)
		all->max_iter += 1;
	else if (all->press->o)
		all->max_iter -= 1;
}

void			move(t_map *all)
{
	if (all->press->left)
		all->center_map[X] += (WIDTH * all->zoom) * 0.1;
	if (all->press->right)
		all->center_map[X] -= (WIDTH * all->zoom) * 0.1;
	if (all->press->up)
		all->center_map[Y] -= (WIDTH * all->zoom) * 0.1;
	if (all->press->down)
		all->center_map[Y] += (WIDTH * all->zoom) * 0.1;
}

void			basic(t_map *all)
{
	if (all->press->one)
		all->name = &fractal_third;
	else if (all->press->two)
		all->name = &fractal_mandelbrot;
	else if (all->press->three)
		all->name = &fractal_julia;
	else if (all->press->three)
		all->name = &fractal_burningship;
	if (all->press->five || all->press->four || all->press->three
	|| all->press->two || all->press->one)
	{
		all->center_map[X] = LENGTH / 2;
		all->center_map[Y] = WIDTH / 2;
		all->zoom = 1;
		all->wd_scale = 0;
		all->tp_scale = 0;
		all->max_iter = 35;
		all->mouse[X] = 0.388333;
		all->mouse[Y] = -0.3001667;
	}
}
