/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:13:11 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:13:13 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	projection(t_fdf *fdf, int key)
{
	if (key == MAIN_PAD_I)
	{
		fdf->alpha = 0;
		fdf->beta = 0;
		fdf->gamma = 0;
		fdf->projection = ISOMETRIC;
	}
	if (key == MAIN_PAD_P)
	{
		fdf->alpha = 0;
		fdf->beta = 0;
		fdf->gamma = 0;
		fdf->projection = PARALLEL;
	}
}

void	z_zoom(t_fdf *fdf, int key)
{
	if (key == MAIN_PAD_LESS)
		fdf->z_zoom -= 0.1;
	if (key == MAIN_PAD_MORE)
		fdf->z_zoom += 0.1;
	if (fdf->z_zoom < 0.3)
		fdf->z_zoom = 0.3;
	else if (fdf->z_zoom > 10)
		fdf->z_zoom = 10;
}

void	zoom(t_fdf *fdf, int key)
{
	if (key == NUM_PAD_MINUS)
		fdf->zoom -= 1;
	if (key == NUM_PAD_PLUS)
		fdf->zoom += 1;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
}

void	move(t_fdf *fdf, int key)
{
	if (key == ARROW_LEFT)
		fdf->x_shift -= 10;
	if (key == ARROW_RIGHT)
		fdf->x_shift += 10;
	if (key == ARROW_DOWN)
		fdf->y_shift += 10;
	if (key == ARROW_UP)
		fdf->y_shift -= 10;
}

void	rotate(t_fdf *fdf, int key)
{
	if (key == NUM_PAD_8)
		fdf->alpha -= 0.0349066;
	if (key == NUM_PAD_2)
		fdf->alpha += 0.0349066;
	if (key == NUM_PAD_4)
		fdf->beta -= 0.0349066;
	if (key == NUM_PAD_6)
		fdf->beta += 0.0349066;
	if (key == NUM_PAD_7)
		fdf->gamma -= 0.0349066;
	if (key == NUM_PAD_9)
		fdf->gamma += 0.0349066;
}
