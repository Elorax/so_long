/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:38:05 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/05 08:49:13 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*void	*ft_strndup(char const *s, int begin, int end)
{
	char	*dest;
	int		i;
	int		j;

	i = begin;
	j = 0;
	dest = (char *) malloc(sizeof(char) * (end - begin + 2));
	if (!dest)
		return (NULL);
	while (i <= end)
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = 0;
	return (dest);
}*/

void	ft_strcpy(char *dest, char *src, int begin, int end)
{
	while (begin <= end)
		*dest++ = src[begin++];
	*dest = 0;
}

t_list	*ft_lstnnew(void *s, int begin, int end)
{
	t_list	*l;

	l = (t_list *) malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	ft_strcpy(l->content, (char *) s, begin, end);
	l->next = NULL;
	return (l);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cursor;

	if (alst && *alst)
	{
		cursor = *alst;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new;
	}
	else if (alst)
		*alst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cursor;

	i = 0;
	cursor = lst;
	while (cursor)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst || !(*lst))
		return ;
	temp = *lst;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
