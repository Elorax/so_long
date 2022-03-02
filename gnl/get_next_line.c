/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:37:59 by abiersoh          #+#    #+#             */
/*   Updated: 2021/11/26 02:48:59 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	clean_buffer(t_buf *reader)
{
	int	i;

	i = 0;
	while (i < reader->memo)
	{
		reader->buffer[i] = 0;
		i++;
	}
}

void	check_eol(int fd, t_count *count, t_buf *r, t_list **lst)
{
	if (r->memo < BUFFER_SIZE && r->buffer[r->memo] == '\n')
	{
		ft_lstadd_back(lst, ft_lstnnew(r->buffer, r->begin, r->memo));
		count->end = 1;
		r->begin = r->memo + 1;
		r->memo++;
	}
	else if (((r->memo < BUFFER_SIZE) && !(r->buffer[r->memo]))
		|| (r->memo == BUFFER_SIZE))
	{
		ft_lstadd_back(lst, ft_lstnnew(r->buffer, r->begin, r->memo));
		clean_buffer(r);
		if (!read(fd, r->buffer, BUFFER_SIZE))
			count->end = 1;
		r->memo = 0;
		r->begin = 0;
	}
}

char	*ft_makeline(t_list *lst, int n)
{
	size_t	i;
	char	*dest;
	t_list	*cursor;
	size_t	j;
	char	*cpy;

	dest = (char *) malloc((((ft_lstsize(lst)) * BUFFER_SIZE) + n + 2));
	if (!dest)
		return (NULL);
	i = 0;
	cursor = lst;
	j = 0;
	while (cursor)
	{
		j = 0;
		cpy = cursor->content;
		while (cpy[j])
		{
			dest[i++] = cpy[j++];
		}
		cursor = cursor->next;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static t_buf	reader = {.buffer = "", .memo = 0, .begin = 0};
	char			*dest;
	t_count			count;
	t_list			*lst;

	count.end = 0;
	if (!(reader.buffer[0]) && (read(fd, reader.buffer, BUFFER_SIZE) <= 0))
		return (NULL);
	lst = NULL;
	while (!count.end)
	{
		while (reader.memo < BUFFER_SIZE
			&& reader.buffer[reader.memo] && reader.buffer[reader.memo] != '\n')
			reader.memo++;
		check_eol(fd, &count, &reader, &lst);
	}
	dest = ft_makeline(lst, reader.memo);
	ft_lstclear(&lst, &free);
	if (!dest || !(*dest))
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}
