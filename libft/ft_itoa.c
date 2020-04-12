/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:14:25 by eberta            #+#    #+#             */
/*   Updated: 2019/09/13 13:33:20 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static int		ft_size(long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		i;

	num = n;
	str = (char*)malloc(sizeof(char) * ft_size(num) + 1);
	if (str == NULL)
		return (NULL);
	i = ft_size(num);
	if (num == 0)
	{
		str[0] = 0 + '0';
		str[1] = '\0';
		return (str);
	}
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	num *= 10;
	str[i--] = '\0';
	while ((num /= 10) > 0)
		str[i--] = num % 10 + '0';
	return (str);
}
