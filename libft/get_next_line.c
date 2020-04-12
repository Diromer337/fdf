/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 00:15:30 by eberta            #+#    #+#             */
/*   Updated: 2019/10/07 00:15:50 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_strlist	*ft_add_in_tail(t_strlist *head, const char *s)
{
	t_strlist	*new_item;
	t_strlist	*current;

	new_item = (t_strlist*)malloc(sizeof(t_strlist));
	new_item->data = ft_strdup(s);
	new_item->next = NULL;
	if (!head)
		return (new_item);
	current = head;
	while (current->next)
		current = current->next;
	current->next = new_item;
	return (head);
}

static t_strlist	*ft_remove_on_head(t_strlist *head)
{
	t_strlist	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	head = head->next;
	free(tmp->data);
	free(tmp);
	return (head);
}

static t_strlist	*write_tail(t_strlist *tail, const char *str, int *end)
{
	char	*n_pointer;

	n_pointer = NULL;
	*end = 0;
	while (str)
	{
		if ((n_pointer = ft_strchr(str, '\n')))
		{
			*n_pointer = '\0';
			tail = ft_add_in_tail(tail, str);
			n_pointer++;
			*end = 1;
			tail = ft_add_in_tail(tail, "\n");
			str = n_pointer;
		}
		else
		{
			tail = ft_add_in_tail(tail, str);
			str = NULL;
		}
	}
	return (tail);
}

static t_strlist	*read_tail(t_strlist *tail, char **line, int *end)
{
	char	*tmp;

	*end = 0;
	if (!ft_strcmp(tail->data, "\n"))
	{
		tail = ft_remove_on_head(tail);
		*end = 1;
		return (tail);
	}
	else
	{
		while (tail && ft_strcmp(tail->data, "\n"))
		{
			tmp = *line;
			*line = ft_strjoin(*line, tail->data);
			free(tmp);
			tail = ft_remove_on_head(tail);
		}
		if (tail && !ft_strcmp(tail->data, "\n"))
		{
			*end = 1;
			return (tail = ft_remove_on_head(tail));
		}
		return (tail);
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_strlist	*tail[FDMAX] = {NULL};
	char				buf[BUFF_SIZE + 1];
	int					byte;
	int					end_count;

	if (fd < 0 || fd > FDMAX || line == NULL)
		return (-1);
	end_count = 0;
	*line = ft_strnew(1);
	if (tail[fd])
		tail[fd] = read_tail(tail[fd], line, &end_count);
	while (!end_count && (byte = read(fd, buf, BUFF_SIZE)))
	{
		if (byte <= 0)
			return (-1);
		buf[byte] = '\0';
		tail[fd] = write_tail(tail[fd], buf, &end_count);
		if (end_count)
		{
			tail[fd] = read_tail(tail[fd], line, &end_count);
			break ;
		}
		tail[fd] = read_tail(tail[fd], line, &end_count);
	}
	return (!tail[fd] && !ft_strlen(*line) ? 0 : 1);
}
