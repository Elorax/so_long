/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:45:09 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 03:33:00 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	char	*cpy;
	char	*cpys1;

	cpys1 = s1;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (free(s1), NULL);
	cpy = dest;
	while (*s1)
	{
		*dest++ = *s1++;
	}
	while (*s2)
	{
		*dest++ = *s2++;
	}
	*dest = 0;
	free(cpys1);
	return (cpy);
}

char	*ft_strjoin2(char *s1, char *s2, int a, int b)
{
	char	*dest;
	char	*cpy;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	cpy = dest;
	while (s1[i])
		*dest++ = s1[i++];
	i = 0;
	while (s2[i])
		*dest++ = s2[i++];
	*dest = 0;
	if (a)
		free(s1);
	if (b)
		free(s2);
	return (cpy);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[++i])
	{
		dest[i] = s[i];
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_so_long_strndup(char *s, int n)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(n + 1);
	if (!dest)
		return (NULL);
	while (s[++i] && i < n)
	{
		dest[i] = s[i];
	}
	dest[i] = 0;
	return (dest);
}
