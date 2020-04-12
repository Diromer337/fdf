/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:11:30 by eberta            #+#    #+#             */
/*   Updated: 2020/02/14 18:11:31 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_replace(char *str, char to_replace, char replace)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_replace)
			str[i] = replace;
		i++;
	}
}
