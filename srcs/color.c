/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:51:50 by tebatsai          #+#    #+#             */
/*   Updated: 2019/10/25 00:17:55 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int g_colr[125] = {
	0xff0000, 0xff3333, 0xff5050, 0xff6666, 0xff9999,
	0xff4000, 0xff6633, 0xff7d52, 0xff8c66, 0xffb399,
	0xff8000, 0xff9933, 0xffa852, 0xffb366, 0xffcc99,
	0xffbf00, 0xffcc33, 0xffd452, 0xffcc66, 0xffe699,
	0xffff00, 0xffff33, 0xffff52, 0xffd966, 0xffff99,
	0xbfff00, 0xccff33, 0xd4ff52, 0xffff66, 0xe6ff99,
	0x80ff00, 0x99ff33, 0xa8ff52, 0xd9ff66, 0xccff99,
	0x40ff00, 0x66ff33, 0x7dff52, 0xb3ff66, 0xb3ff99,
	0x00ff00, 0x33ff33, 0x52ff52, 0x8cff66, 0x99ff99,
	0x00ff40, 0x33ff66, 0x52ff7d, 0x66ff66, 0x99ffb3,
	0x00ff80, 0x33ff99, 0x52ffa8, 0x66ff8c, 0x99ffcc,
	0x00ffbf, 0x33ffcc, 0x52ffd4, 0x66ffb3, 0x99ffe6,
	0x00ffff, 0x33ffff, 0x52ffff, 0x66ffd9, 0x99ffff,
	0x00bfff, 0x33ccff, 0x52d4ff, 0x66ffff, 0x99e6ff,
	0x0080ff, 0x3399ff, 0x52a8ff, 0x66d9ff, 0x99ccff,
	0x0040ff, 0x3366ff, 0x527dff, 0x66b3ff, 0x99b3ff,
	0x0000ff, 0x3333ff, 0x5252ff, 0x668cff, 0x9999ff,
	0x4000ff, 0x6633ff, 0x7d52ff, 0x6666ff, 0xb399ff,
	0x8000ff, 0x9933ff, 0xa852ff, 0x8c66ff, 0xcc99ff,
	0xbf00ff, 0xcc33ff, 0xd452ff, 0xb366ff, 0xe699ff,
	0xff00ff, 0xff33ff, 0xff52ff, 0xd966ff, 0xff99ff,
	0xff00bf, 0xff33cc, 0xff52d4, 0xff66ff, 0xff99e6,
	0xff0080, 0xff3399, 0xff52a8, 0xff66d9, 0xff99cc,
	0xff0040, 0xff3366, 0xff527d, 0xff66b3, 0xff99b3,
	0xff0000, 0xff3333, 0xff5252, 0xff668c, 0xff9999};

unsigned int		mix(unsigned int x, unsigned int y, float gap)
{
	int				r;
	int				g;
	int				b;
	unsigned int	ret;

	r = (((int)(float)(x >> 16 & 255) * (1 - gap))\
	+ (float)((y >> 16 & 255) * gap));
	g = (((int)(float)(x >> 8 & 255) * (1 - gap))\
	+ (float)((y >> 8 & 255) * gap));
	b = ((int)(float)(x & 255) * (1 - gap)) + (float)((y & 255) * gap);
	r = (r > 0xFF) ? 255 : r;
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	ret = r << 16 | g << 8 | b;
	return (ret);
}

void				set_everything(t_map *all)
{
	int				i;

	i = 0;
	mlx_clear_window(all->mlx, all->window);
	haha(all, 0, 0);
}

void				haha(t_map *all, int q, int w)
{
	int				x;

	x = 0;
	while (w < WIDTH)
	{
		q = 0;
		while (q < LENGTH)
		{
			x = all->name(all, (double)q, (double)w);
			all->data[(w * WIDTH) + q] = x == 0 ? 0 : blend_max(all, x % 75);
			q++;
		}
		w++;
	}
}

unsigned int		blend_max(t_map *all, int x)
{
	unsigned int	w;

	x = (all->x + x) % 75;
	w = g_colr[x];
	w = mix(w, g_colr[x + 1], 0.5);
	return (w);
}
