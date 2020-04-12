/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:02:58 by eberta            #+#    #+#             */
/*   Updated: 2019/09/05 18:09:24 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	num(int nb)
{
	if (nb >= 10 || nb <= -10)
	{
		num(nb / 10);
		num(nb % 10);
	}
	else if (nb >= 0)
		ft_putchar(nb + '0');
	else
		ft_putchar(-1 * nb + '0');
}

void		ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	num(nb);
}
