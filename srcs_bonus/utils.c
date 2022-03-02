/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:45:09 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 03:32:45 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_itoa(int n)
{
	int				i;
	char			*dest;
	unsigned int	cpy;

	i = ((cpy = (n * (1 - (2 * (n < 0))))), (n < 0));
	while (cpy > 9)
		cpy = (i++, cpy / 10);
	dest = malloc(i + 2);
	if (!dest)
		return (NULL);
	dest[i + 1] = 0;
	dest[0] = ((cpy = (n * (1 - (2 *(n < 0))))), '-' + 3 * (n == 0));
	while (cpy > 0)
		cpy = ((dest[i--] = (cpy % 10) + '0'), cpy / 10);
	return (dest);
}

int	ft_atoi(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
		return (0);
	while (*s && *s <= '9' && *s >= '0')
	{
		ret = (ret * 10) + (*s - '0');
		s++;
	}
	return (ret);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (str - 1);
	return (NULL);
}

void	ft_cswitch(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
