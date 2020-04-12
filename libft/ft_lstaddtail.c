/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:58:29 by eberta            #+#    #+#             */
/*   Updated: 2019/09/18 17:58:30 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = *alst;
	if (new != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}
