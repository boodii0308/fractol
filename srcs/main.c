/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:51:50 by tebatsai          #+#    #+#             */
/*   Updated: 2019/10/25 00:34:48 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_map			*newin(void)
{
	t_map *all;

	all = (t_map *)malloc(sizeof(t_map));
	all->mlx = mlx_init();
	all->img = NULL;
	all->window = NULL;
	all->data = NULL;
	all->bits_per_pixel = 8;
	all->size_line = 0;
	all->endian = 0;
	all->wd_scale = 0;
	all->tp_scale = 0;
	all->x = 0;
	all->zoom = 1.0;
	all->center_map[X] = LENGTH / 2;
	all->center_map[Y] = WIDTH / 2;
	all->mouse[X] = 0.388333;
	all->mouse[Y] = -0.3001667;
	all->max_iter = 5;
	all->toggle = 0;
	all->trigger = 2;
	all->press = (t_keys *)malloc(sizeof(t_keys));
	return (all);
}

void			ft_window(t_map *all)
{
	all->window = mlx_new_window(all->mlx, LENGTH, WIDTH, "Fractal - 42");
	all->img = mlx_new_image(all->mlx, LENGTH, WIDTH);
	all->data = (int *)mlx_get_data_addr(all->img, &all->bits_per_pixel
	, &all->size_line, &all->endian);
	setting(all);
}

void			setting(t_map *all)
{
	set_everything(all);
	set_control(all);
	mlx_put_image_to_window(all->mlx, all->window, all->img, 0, 0);
}

void			split(t_map *all, char **arv)
{
	int i;

	i = all->x - 1;
	while (i > 0)
	{
		if (arv[i][0] == '1')
			all->name = &fractal_third;
		else if (arv[i][0] == '2')
			all->name = &fractal_mandelbrot;
		else if (arv[i][0] == '3')
		{
			all->name = &fractal_julia;
			all->toggle = 1;
		}
		else if (arv[i][0] == '4')
			all->name = &fractal_burningship;
		else
		{
			write(1, "Given input is not valid input\n", 32);
			exit(0);
		}
		ft_window(all);
		i--;
	}
	return ;
}

int				main(int arc, char **arv)
{
	t_map	*all;

	if (arc >= 2)
	{
		all = newin();
		all->x = arc;
		split(all, arv);
		mlx_loop(all->mlx);
	}
	else
		write(1, "Pls execute with file\n", 23);
	return (0);
}
