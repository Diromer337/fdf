/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:14:00 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:14:01 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_height(const char *file)
{
	int		fd;
	char	*line;
	int		height;

	if ((fd = open(file, O_RDONLY, 0)) == -1)
		return (-1);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int		get_width(const char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = word_num(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		if ((word_num(line, ' ')) != width)
			return (-1);
		free(line);
	}
	free(line);
	close(fd);
	return (width);
}

void	init_matrix(t_fdf *fdf)
{
	int		i;

	fdf->matrix = (int**)malloc(sizeof(int*) * (fdf->height + 1));
	fdf->color = (int**)malloc(sizeof(int*) * (fdf->height + 1));
	i = 0;
	while (i <= fdf->height)
	{
		fdf->matrix[i] = (int*)malloc(sizeof(int) * (fdf->width + 1));
		fdf->color[i] = (int*)malloc(sizeof(int) * (fdf->width + 1));
		i++;
	}
}

int		read_file(const char *file, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;

	if ((fdf->height = get_height(file)) == -1)
		return (0);
	if ((fdf->width = get_width(file)) == -1)
		return (0);
	init_matrix(fdf);
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		if ((parse_line(fdf->matrix[i], fdf->color[i], line, fdf)) == -1)
		{
			free(line);
			return (0);
		}
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (1);
}
