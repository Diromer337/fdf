/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:14:06 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:14:07 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(float *y, float *z, t_fdf *fdf)
{
	float	y_t;

	y_t = *y;
	*y = y_t * cos(fdf->alpha) + *z * sin(fdf->alpha);
	*z = -y_t * sin(fdf->alpha) + *z * cos(fdf->alpha);
}

void	rotate_y(float *x, float *z, t_fdf *fdf)
{
	float	x_t;

	x_t = *x;
	*x = x_t * cos(fdf->beta) + *z * sin(fdf->beta);
	*z = -x_t * sin(fdf->beta) + *z * cos(fdf->beta);
}

void	rotate_z(float *x, float *y, t_fdf *fdf)
{
	float	y_t;
	float	x_t;

	y_t = *y;
	x_t = *x;
	*x = x_t * cos(fdf->gamma) - y_t * sin(fdf->gamma);
	*y = x_t * sin(fdf->gamma) + y_t * cos(fdf->gamma);
}
