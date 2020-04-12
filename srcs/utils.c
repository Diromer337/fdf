/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:52:21 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:52:22 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		swap(float *a, float *b, float *c, float *d)
{
	float	temp1;
	float	temp2;

	temp1 = *a;
	*a = *b;
	*b = temp1;
	temp2 = *c;
	*c = *d;
	*d = temp2;
}

void		point_zoom(t_point *p1, t_point *p2, int zoom)
{
	p1->x *= zoom;
	p1->y *= zoom;
	p2->x *= zoom;
	p2->y *= zoom;
}

t_point		create_point(int x, int y)
{
	t_point		new;

	new.x = x;
	new.y = y;
	return (new);
}

int			min(int a, int b)
{
	return (a > b ? b : a);
}

float		count_y(int *error, int ystep, int dx, int dy)
{
	float	y;

	y = 0.0;
	*error -= dy;
	if (*error < 0)
	{
		y = ystep;
		*error += dx;
	}
	return (y);
}
