/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:13:32 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:13:34 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		clear_fields(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i <= fdf->height)
	{
		free(fdf->matrix[i]);
		free(fdf->color[i]);
		i++;
	}
	free(fdf->matrix);
	free(fdf->color);
}

int			win_close(t_fdf *fdf)
{
	clear_fields(fdf);
	exit(0);
}

int			deal_key(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_ESC)
		win_close(fdf);
	if (key == MAIN_PAD_I || key == MAIN_PAD_P)
		projection(fdf, key);
	if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		z_zoom(fdf, key);
	if (key == NUM_PAD_4 || key == NUM_PAD_6
			|| key == NUM_PAD_8 || key == NUM_PAD_2
			|| key == NUM_PAD_7 || key == NUM_PAD_9)
		rotate(fdf, key);
	if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		zoom(fdf, key);
	if (key == ARROW_UP || key == ARROW_DOWN
			|| key == ARROW_RIGHT || key == ARROW_LEFT)
		move(fdf, key);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf);
	return (0);
}

void		controls(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, win_close, fdf);
}
