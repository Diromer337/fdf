/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:21:22 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:21:23 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "../libft/libft.h"
# include "math.h"
# include "keys.h"
# define WINDOW_SIZE_H 1080
# define WINDOW_SIZE_W 1920
# define MENU_SIZE 250
# define TEXT_COLOR 0xEAEAEA
# define MAIN_PAD_I			34
# define MAIN_PAD_P			35

enum					e_projection
{
	ISOMETRIC,
	PARALLEL
};

typedef struct			s_fdf
{
	int					height;
	int					width;
	int					**matrix;
	int					**color;
	int					z_max;
	int					z_min;
	float				color_step;
	int					zoom;
	float				z_zoom;
	int					x_shift;
	int					y_shift;
	float				alpha;
	float				beta;
	float				gamma;
	enum e_projection	projection;
	void				*win_ptr;
	void				*mlx_ptr;
}						t_fdf;

typedef struct			s_point
{
	float				x;
	float				y;
}						t_point;

int						read_file(const char *file, t_fdf *fdf);
void					draw(t_fdf *data);
void					rotate_x(float *y, float *z, t_fdf *fdf);
void					rotate_y(float *x, float *z, t_fdf *fdf);
void					rotate_z(float *x, float *y, t_fdf *fdf);
t_fdf					*init_fdf(const char *file);
void					controls(t_fdf *fdf);
void					move(t_fdf *fdf, int key);
void					rotate(t_fdf *fdf, int key);
void					zoom(t_fdf *fdf, int key);
void					z_zoom(t_fdf *fdf, int key);
void					print_menu(t_fdf *fdf);
void					projection(t_fdf *fdf, int key);
int						parse_line(int *z, int *color, char *line, t_fdf *fdf);
void					swap(float *a, float *b, float *c, float *d);
void					colorize(t_fdf *fdf);
void					point_zoom(t_point *p1, t_point *p2, int zoom);
t_point					create_point(int x, int y);
int						min(int a, int b);
float					count_y(int *error, int ystep, int dx, int dy);
#endif
