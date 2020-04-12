/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:13:18 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:13:19 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		colorize(t_fdf *fdf)
{
	static int		color[11] = {0x90EE90, 0x00FF7F, 0x2E8B57, 0x008000,
						0x006400, 0x808000, 0x7e5429, 0x654321, 0x51361a,
						0x981501, 0x702b69};
	int				y;
	int				x;

	y = 0;
	fdf->color_step = (fdf->z_max - fdf->z_min) / 10.0;
	fdf->color_step = fdf->color_step > 0 ? fdf->color_step : 1;
	while (y <= fdf->height)
	{
		x = 0;
		while (x <= fdf->width)
		{
			if (fdf->color[y][x] == -1)
			{
				fdf->color[y][x] =
				color[(int)((fdf->matrix[y][x] - fdf->z_min) /
												fdf->color_step)];
			}
			x++;
		}
		y++;
	}
}

void		isometric(float *x0, float *y0, float z0)
{
	float	x_t;
	float	y_t;

	x_t = *x0;
	y_t = *y0;
	*x0 = (x_t - y_t) * cos(0.523599);
	*y0 = -z0 + (x_t + y_t) * sin(0.523599);
}

void		scale(t_point *p1, t_point *p2, t_fdf *fdf)
{
	float	z0;
	float	z1;

	z0 = fdf->matrix[(int)p1->y][(int)p1->x] * ((fdf->zoom) / fdf->z_zoom);
	z1 = fdf->matrix[(int)p2->y][(int)p2->x] * ((fdf->zoom) / fdf->z_zoom);
	point_zoom(p1, p2, fdf->zoom);
	p1->x -= (fdf->width * fdf->zoom) / 2;
	p2->x -= (fdf->width * fdf->zoom) / 2;
	p1->y -= (fdf->height * fdf->zoom) / 2;
	p2->y -= (fdf->height * fdf->zoom) / 2;
	rotate_x(&p1->y, &z0, fdf);
	rotate_x(&p2->y, &z1, fdf);
	rotate_y(&p1->x, &z0, fdf);
	rotate_y(&p2->x, &z1, fdf);
	rotate_z(&p1->x, &p1->y, fdf);
	rotate_z(&p2->x, &p2->y, fdf);
	if (fdf->projection == ISOMETRIC)
	{
		isometric(&p1->x, &p1->y, z0);
		isometric(&p2->x, &p2->y, z1);
	}
	p1->x += (WINDOW_SIZE_W - MENU_SIZE) / 2 + fdf->x_shift + MENU_SIZE;
	p1->y += (WINDOW_SIZE_H + fdf->height * fdf->zoom) / 3 + fdf->y_shift;
	p2->x += (WINDOW_SIZE_W - MENU_SIZE) / 2 + fdf->x_shift + MENU_SIZE;
	p2->y += (WINDOW_SIZE_H + fdf->height * fdf->zoom) / 3 + fdf->y_shift;
}

void		line(t_point p1, t_point p2, int color, t_fdf *fdf)
{
	int		step;
	int		dx;
	int		dy;
	int		error;
	int		ystep;

	scale(&p1, &p2, fdf);
	step = fabsf(p2.y - p1.y) > fabsf(p2.x - p1.x);
	if (step)
		swap(&p1.x, &p1.y, &p2.x, &p2.y);
	if (p1.x > p2.x)
		swap(&p1.x, &p2.x, &p1.y, &p2.y);
	dx = p2.x - p1.x;
	dy = fabsf(p2.y - p1.y);
	error = dx / 2;
	ystep = (p2.y > p1.y) ? 1 : -1;
	while (p1.x < p2.x)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, step ? p1.y : p1.x,
					step ? p1.x : p1.y, color);
		p1.y = p1.y + count_y(&error, ystep, dx, dy);
		p1.x++;
	}
}

void		draw(t_fdf *fdf)
{
	int		x;
	int		y;
	int		color;

	y = -1;
	while (++y < fdf->height)
	{
		x = -1;
		while (++x < fdf->width)
		{
			if (x < fdf->width - 1)
			{
				color = fdf->matrix[y][x + 1] > fdf->matrix[y][x] ?
									fdf->color[y][x + 1] : fdf->color[y][x];
				line(create_point(x, y), create_point(x + 1, y), color, fdf);
			}
			if (y < fdf->height - 1)
			{
				color = fdf->matrix[y + 1][x] > fdf->matrix[y][x] ?
									fdf->color[y + 1][x] : fdf->color[y][x];
				line(create_point(x, y), create_point(x, y + 1), color, fdf);
			}
		}
	}
	print_menu(fdf);
}
