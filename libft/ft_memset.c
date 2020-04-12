/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:14:10 by eberta            #+#    #+#             */
/*   Updated: 2019/09/12 17:14:13 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned long	i;
	unsigned char	*p;

	p = memptr;
	i = 0;
	while (i < num)
	{
		p[i] = val;
		i++;
	}
	return (p);
}
