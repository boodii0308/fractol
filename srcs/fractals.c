/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:51:50 by tebatsai          #+#    #+#             */
/*   Updated: 2019/10/25 00:28:22 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			fractal_burningship(t_map *all, double x, double y)
{
	double	p[2];
	double	q[2];
	double	w[2];
	int		i;

	i = 0;
	q[0] = ((double)x - all->center_map[X]) / ((LENGTH / 4)
	* all->zoom) + all->wd_scale;
	q[1] = ((double)y - all->center_map[Y]) / ((WIDTH / 4)
	* all->zoom) + all->tp_scale;
	p[0] = q[0];
	p[1] = q[1];
	while (i < all->max_iter && p[0] * p[0] + p[1] * p[1] < 4)
	{
		w[0] = (p[0] * p[0]) - (p[1] * p[1]);
		w[1] = (2 * p[0] * p[1]);
		p[1] = fabs(w[1] + q[1]);
		p[0] = fabs(w[0] + q[0]);
		i++;
	}
	return (i);
}

int			fractal_third(t_map *all, double x, double y)
{
	double	p[2];
	double	q[2];
	double	w[2];
	int		i;

	i = 0;
	q[0] = ((double)x - all->center_map[X]) / ((LENGTH / 4)
	* all->zoom) + all->wd_scale;
	q[1] = ((double)y - all->center_map[Y]) / ((WIDTH / 4)
	* all->zoom) + all->wd_scale;
	p[0] = q[0];
	p[1] = q[1];
	while (i < all->max_iter && q[0] + q[1] <= 4)
	{
		w[0] = (q[0] * q[0]) - (q[1] * q[1]);
		w[1] = 4 * q[0] * q[1];
		q[0] = w[0] + p[0];
		q[1] = w[1] + p[1];
		i++;
	}
	return (i);
}

int			fractal_mandelbrot(t_map *all, double x, double y)
{
	double	p[2];
	double	q[2];
	double	w[2];
	int		i;

	i = 0;
	q[0] = ((double)x - all->center_map[X]) / ((LENGTH / 4)
	* all->zoom) + all->wd_scale;
	q[1] = ((double)y - all->center_map[Y]) / ((WIDTH / 4)
	* all->zoom) + all->tp_scale;
	p[0] = q[0];
	p[1] = q[1];
	while (i < all->max_iter && q[0] * q[0] + q[1] * q[1] <= 4)
	{
		w[0] = (q[0] * q[0]) - (q[1] * q[1]);
		w[1] = 2 * q[0] * q[1];
		q[0] = w[0] + p[0];
		q[1] = w[1] + p[1];
		i++;
	}
	return (i);
}

int			fractal_julia(t_map *all, double x, double y)
{
	double	p;
	double	q;
	double	w;
	double	n;
	int		i;

	i = 0;
	w = ((double)x - all->center_map[X]) / ((LENGTH / 4)
	* all->zoom) + all->wd_scale;
	q = ((double)y - all->center_map[Y]) / ((WIDTH / 4)
	* all->zoom) + all->wd_scale;
	while (i < all->max_iter && q * q + w * w <= 4)
	{
		n = (w * w) - (q * q);
		p = 2 * w * q;
		q = p + all->mouse[X];
		w = n + all->mouse[Y];
		i++;
	}
	all->toggle = 1;
	return (i);
}
