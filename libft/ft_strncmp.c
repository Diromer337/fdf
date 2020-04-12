/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:51:23 by eberta            #+#    #+#             */
/*   Updated: 2019/09/06 20:20:08 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned long	i;

	if (num == 0)
		return (0);
	i = 0;
	while ((str1[i] == str2[i]) &&
			(str1[i]) && (str2[i]) && (i < num - 1))
	{
		i++;
	}
	if (str1[i] != '\0' || str2[i] != '\0')
	{
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}
