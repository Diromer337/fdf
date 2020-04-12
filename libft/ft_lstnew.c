/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:30:16 by eberta            #+#    #+#             */
/*   Updated: 2019/09/17 19:30:17 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*s;

	s = (t_list*)malloc(sizeof(t_list));
	if (s == NULL)
		return (NULL);
	if (content == NULL)
	{
		s->content = (void*)NULL;
		s->content_size = (unsigned long)NULL;
	}
	else
	{
		if (!(s->content = malloc(sizeof(content_size))))
		{
			free(s);
			return (NULL);
		}
		else
		{
			ft_memcpy(s->content, content, content_size);
			s->content_size = content_size;
		}
	}
	s->next = NULL;
	return (s);
}
