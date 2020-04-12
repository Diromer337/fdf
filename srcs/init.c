/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:13:25 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:13:27 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf		*init_fdf(const char *file)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	fdf->z_max = 0;
	fdf->z_min = 0;
	if (!read_file(file, fdf))
	{
		free(fdf);
		return (NULL);
	}
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WINDOW_SIZE_W,
												WINDOW_SIZE_H, "FDF");
	fdf->zoom = min((WINDOW_SIZE_W - MENU_SIZE) / fdf->width / 2,
										WINDOW_SIZE_H / fdf->height / 2);
	fdf->projection = PARALLEL;
	fdf->z_zoom = 1;
	fdf->x_shift = 0;
	fdf->y_shift = 0;
	fdf->alpha = 0;
	fdf->gamma = 0;
	fdf->beta = 0;
	return (fdf);
}
