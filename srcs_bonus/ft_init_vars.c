/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:29:00 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 19:06:29 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_get_settings(char *src)
{
	char	*dest;

	dest = ft_so_long_strndup(src, ft_strlen(src) - 4);
	dest = ft_strjoin2(dest, ".set", 1, 0);
	return (dest);
}

void	ft_init_file(t_vars *vars)
{
	int	fd;

	fd = 0;
	fd = open(vars->settings, O_RDONLY);
	if (fd > 0)
	{
		vars->objectif = get_next_line(fd);
		vars->mobs_to_kill = get_next_line(fd);
		vars->to_kill = ft_atoi(vars->mobs_to_kill);
	}
	else
	{
		vars->to_kill = ((vars->objectif = ft_strdup("999")), 0);
		vars->mobs_to_kill = NULL;
	}
	close(fd);
}

void	ft_init_vars(t_vars *vars)
{
	vars->koko = 0;
	vars->map.length = ((vars->map.height = 0), 0);
	vars->map.nb_exit = 0;
	vars->map.nb_collec = 0;
	vars->map.nb_player = 0;
	vars->settings = ft_get_settings(vars->av[vars->level]);
	vars->killed = 0;
	vars->collected = 0;
	vars->nb_moves = 0;
	vars->frames = 0;
	vars->dir = up;
	vars->pause = 0;
	vars->begin = clock();
}

int	ft_read_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!(map->map))
		return (-1);
	map->map[i] = get_next_line(map->fd);
	while (map->map[i++])
		map->map[i] = get_next_line(map->fd);
	return (0);
}

int	ft_init_map(t_map *map)
{
	int	i;

	map->nb_player = ((i = 0), 0);
	map->nb_exit = 0;
	map->nb_collec = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!(map->map))
		return (-1);
	map->map[i] = get_next_line(map->fd);
	while (map->map[i])
	{
		if (ft_check_line(map, i) != 0)
			return ((map->map[++i] = NULL), -1);
		if (i > 0 && ft_strlen(map->map[i]) != ft_strlen(map->map[i - 1]))
			return ((map->map[++i] = NULL), -1);
		map->map[++i] = get_next_line(map->fd);
	}
	if ((i > 1) && (ft_check_first_line(map->map[0])
			|| ft_check_first_line(map->map[i - 1])))
		return (-1);
	if (map->nb_player != 1 || map->nb_exit != 1 || map->nb_collec < 1)
		return (-1);
	map->height = i;
	map->length = ft_strlen(map->map[0]) - 1;
	return (0);
}
