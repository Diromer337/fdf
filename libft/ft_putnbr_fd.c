/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:53:54 by eberta            #+#    #+#             */
/*   Updated: 2019/09/13 14:53:57 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	num(int nb, int fd)
{
	if (nb >= 10 || nb <= -10)
	{
		num(nb / 10, fd);
		num(nb % 10, fd);
	}
	else if (nb >= 0)
		ft_putchar_fd(nb + '0', fd);
	else
		ft_putchar_fd(-1 * nb + '0', fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	num(nb, fd);
}
