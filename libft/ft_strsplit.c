/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:36:55 by eberta            #+#    #+#             */
/*   Updated: 2019/09/12 20:37:03 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	next_c(char const *s, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

int			word_num(char const *s, char c)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			num++;
		i++;
	}
	return (num);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	if (!s || !(str = (char**)malloc(sizeof(char*) * word_num(s, c) + 1)))
		return (NULL);
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = (char*)malloc(sizeof(char) * (next_c(s, c, i) - i + 1));
			if (str[j] == NULL)
				return (NULL);
			ft_strncpy(str[j], s + i, next_c(s, c, i) - i);
			str[j][next_c(s, c, i) - i] = '\0';
			j++;
			i = next_c(s, c, i) - 1;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
