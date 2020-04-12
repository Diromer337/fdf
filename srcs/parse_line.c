/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:13:54 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:13:55 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		parse_z(const char *s, int *z, int *color)
{
	char **parts;

	parts = ft_strsplit(s, ',');
	if (!ft_isnumber_base(parts[0], 10))
	{
		free(parts[0]);
		if (parts[1])
			free(parts[1]);
		free(parts);
		return (-1);
	}
	*z = abs(ft_atoi(parts[0])) > 1000 ? 0 : ft_atoi(parts[0]);
	if (parts[1] && !ft_isnumber_base(parts[1], 16))
	{
		free(parts[0]);
		free(parts[1]);
		free(parts);
		return (-1);
	}
	*color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	free(parts[0]);
	if (parts[1])
		free(parts[1]);
	free(parts);
	return (0);
}

int				parse_line(int *z, int *color, char *line, t_fdf *fdf)
{
	char	**str;
	int		i;

	str = ft_strsplit(line, ' ');
	i = 0;
	while (str[i])
	{
		if ((parse_z(str[i], &z[i], &color[i])) == -1)
		{
			while (str[i])
				free(str[i++]);
			free(str);
			return (-1);
		}
		if (z[i] > fdf->z_max)
			fdf->z_max = z[i];
		if (z[i] < fdf->z_min)
			fdf->z_min = z[i];
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}
