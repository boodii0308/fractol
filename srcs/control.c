/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:51:50 by tebatsai          #+#    #+#             */
/*   Updated: 2019/10/25 00:19:07 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void			set_control(t_map *all)
{
	mlx_do_key_autorepeatoff(all->mlx);
	mlx_hook(all->window, 2, 0, keypress, all);
	mlx_hook(all->window, 3, 0, keyrelease, all);
	mlx_mouse_hook(all->window, mousepress, all);
	if (all->press->space && all->toggle)
	{
		mlx_hook(all->window, 6, 0, motion, all);
	}
	mlx_hook(all->window, 17, 0, exit_window, all);
	mlx_loop_hook(all->mlx, rotation, all);
}

int				motion(int x, int y, t_map *all)
{
	if (all->toggle == 0 || x > WIDTH || y > LENGTH)
		return (0);
	if (all->press->space && all->toggle)
	{
		all->mouse[X] = ((((double)x - WIDTH) / (WIDTH / 2)) + 1);
		all->mouse[Y] = ((((double)y - WIDTH) / (WIDTH / 2)) + 1);
	}
	setting(all);
	return (0);
}

int				keypress(int key, t_map *all)
{
	if (key == 53)
		exit(0);
	else
		check_press(key, all, 1);
	return (0);
}

int				keyrelease(int key, t_map *all)
{
	check_press(key, all, 0);
	return (0);
}

int				exit_window(t_map *all)
{
	mlx_destroy_window(all->mlx, all->window);
	exit(0);
}
