/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:18:19 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/19 22:03:55 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_check_line(t_map *map, int i)
{
	char	*str;

	str = map->map[i];
	if (*str != '1')
		return (-1);
	while (*str)
	{
		if (!ft_strchr("0b1PBDECRLX\n", *str))
			return (-1);
		else
		{
			if (*str == 'E')
				map->nb_exit++;
			else if (*str == 'C')
				map->nb_collec++;
			else if (*str == 'P')
				map->nb_player++;
			str++;
		}
	}
	if (*(str - 2) != '1')
		return (-1);
	return (0);
}

int	ft_check_first_line(char *str)
{
	while (*str && *str != '\n')
		if ((*str++ != '1'))
			return (-1);
	return (0);
}

int	ft_count_lines(t_map map)
{
	char	*str;
	int		i;

	str = get_next_line(map.fd);
	i = 0;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(map.fd);
		i++;
	}
	return (i);
}

int	is_name_valid(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i > 3 && av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b'
		&& av[i - 4] == '.')
		return (1);
	else
		return (printf("map name should end in \".ber\"\n"), 0);
}
