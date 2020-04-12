/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:20:16 by eberta            #+#    #+#             */
/*   Updated: 2019/09/13 22:20:18 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (string[i])
	{
		if (string[i] == symbol)
			j = i;
		i++;
	}
	if (symbol == 0)
		return ((char*)(string + i));
	if (j != -1)
		return ((char*)(string + j));
	else
		return (NULL);
}
