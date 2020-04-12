/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:21:33 by eberta            #+#    #+#             */
/*   Updated: 2019/09/13 18:21:35 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	int				sign;

	if (!dst && !src)
		return (NULL);
	i = 0;
	sign = (dst < src ? 1 : -1);
	d = dst + (dst < src ? 0 : len - 1);
	s = (unsigned char*)src + (dst < src ? 0 : len - 1);
	while (i < len)
	{
		*d = *s;
		d += sign;
		s += sign;
		i++;
	}
	return (dst);
}
