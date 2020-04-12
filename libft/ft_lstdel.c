/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:18:04 by eberta            #+#    #+#             */
/*   Updated: 2019/09/17 21:18:06 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*tmp;

	temp = *alst;
	while (temp != NULL)
	{
		tmp = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = tmp;
	}
	*alst = NULL;
}
