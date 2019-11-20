/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:17:17 by tebatsai          #+#    #+#             */
/*   Updated: 2019/10/25 00:26:16 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"
# include "key.h"
# include <pthread.h>
# include <math.h>
# define WIDTH 600
# define LENGTH 600
# define X 0
# define Y 1
# define Z 2
# define TD 6
# define PI 3.14159265
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define WHITE 0xFFFFFF

typedef struct s_map	t_map;
struct					s_map
{
	void				*img;
	void				*mlx;
	void				*window;
	int					*data;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					map_height;
	int					map_width;
	int					map_length;
	int					x;
	int					center_map[2];
	double				wd_scale;
	double				tp_scale;
	unsigned int		color_set[3];
	double				zoom;
	int					trigger;
	double				mouse[2];
	int					toggle;
	int					max_iter;
	pthread_t			tr[TD];
	t_keys				*press;
	int					(*name)(struct s_map *all, double x, double y);
};

int						fractal_third(t_map *all, double x, double y);
int						fractal_mandelbrot(t_map *all, double x, double y);
int						fractal_julia(t_map *all, double x, double y);
int						fractal_burningship(t_map *all, double x, double y);
unsigned int			blend_max(t_map *all, int x);
unsigned int			rainbow (t_map *all, int x, int y);
unsigned int			mix(unsigned int x, unsigned int y, float gap);
float					percent(int f, int s, int cur);
void					set_everything(t_map *all);
void					haha(t_map *all, int i, int w);
void					*build(void *lol);
int						finish(int fd, t_map *all, char **map);
void					setting(t_map *all);
int						main(int arc, char **arv);
void					connect_thread(t_map *all);
void					check_press(int key, t_map *all, int i);
void					check_touch(int key, t_map *all, int i);
int						motion(int x, int y, t_map *all);
int						mouse(int x, int y, t_map *all);
int						mouserelease(int key, int x, int y, t_map *all);
int						mousepress(int key, int x, int y, t_map *all);
void					set_control(t_map *all);
int						keypress(int key, t_map *all);
int						keyrelease(int key, t_map *all);
int						exit_window(t_map *all);
void					color(t_map *all);
int						rotation(t_map *all);
void					zoom(t_map *all);
void					move(t_map *all);
void					basic(t_map *all);
#endif
