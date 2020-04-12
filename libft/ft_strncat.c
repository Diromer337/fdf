/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:10:26 by eberta            #+#    #+#             */
/*   Updated: 2019/09/05 18:30:45 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strncat(char *destptr, char *srcptr, size_t num)
{
	int				i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (destptr[i])
	{
		i++;
	}
	while (srcptr[j] && (j < num))
	{
		destptr[i] = srcptr[j];
		i++;
		j++;
	}
	destptr[i] = '\0';
	return (destptr);
}
