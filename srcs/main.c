/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:13:39 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:13:40 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "stdio.h"

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		if (!(fdf = init_fdf(argv[1])))
		{
			ft_putstr("Incorrect MAP_FILE\n");
			return (1);
		}
		printf("%d\n", fdf->matrix[fdf->height][fdf->width]);
		colorize(fdf);
		draw(fdf);
		controls(fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
	{
		ft_putstr("Usage: ./fdf MAP_FILE\n");
	}
	return (0);
}
