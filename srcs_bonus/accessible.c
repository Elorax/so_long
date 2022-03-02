/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:01:03 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/29 10:47:14 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	is_accessible_up(t_vars vars, int x, int y)
{
	if (ft_strchr(ACCESSIBLE_CASE, vars.map.map[y - 1][x]))
		return (1);
	if (vars.map.map[y - 1][x] == 'E'
		&& vars.collected == vars.map.nb_collec
		&& vars.killed >= vars.to_kill)
		return (1);
	else if (y > 2
		&& ft_strchr("#xXb", vars.map.map[y - 1][x])
		&& ft_strchr("0B", vars.map.map[y - 2][x]))
		return (2);
	else if (y > 2
		&& ft_strchr("#xXb", vars.map.map[y - 1][x])
		&& ft_strchr("RL", vars.map.map[y - 2][x])
		&& ft_strchr("bDxX#1", vars.map.map[y - 3][x]))
		return (3);
	return (0);
}

int	is_accessible_down(t_vars vars, int x, int y)
{
	if (ft_strchr(ACCESSIBLE_CASE, vars.map.map[y + 1][x]))
		return (1);
	if (vars.map.map[y + 1][x] == 'E'
		&& vars.collected == vars.map.nb_collec
		&& vars.killed >= vars.to_kill)
		return (1);
	else if (y < vars.map.height - 2
		&& ft_strchr("Xbx#", vars.map.map[y + 1][x])
		&& ft_strchr("0B", vars.map.map[y + 2][x]))
		return (2);
	else if (y < vars.map.height - 3
		&& ft_strchr("Xx#b", vars.map.map[y + 1][x])
		&& ft_strchr("RL", vars.map.map[y + 2][x])
		&& ft_strchr("bXxD#1", vars.map.map[y + 3][x]))
		return (3);
	return (0);
}

int	is_accessible_right(t_vars vars, int x, int y)
{
	if (ft_strchr(ACCESSIBLE_CASE, vars.map.map[y][x + 1]))
		return (1);
	if (vars.map.map[y][x + 1] == 'E'
		&& vars.collected == vars.map.nb_collec
		&& vars.killed >= vars.to_kill)
		return (1);
	else if (x < vars.map.length - 2
		&& ft_strchr("Xx#b", vars.map.map[y][x + 1])
		&& ft_strchr("0B", vars.map.map[y][x + 2]))
		return (2);
	else if (x < vars.map.length - 3
		&& ft_strchr("Xx#b", vars.map.map[y][x + 1])
		&& ft_strchr("RL", vars.map.map[y][x + 2])
		&& ft_strchr("bXx#1D", vars.map.map[y][x + 3]))
		return (3);
	return (0);
}

int	is_accessible_left(t_vars vars, int x, int y)
{
	if (ft_strchr(ACCESSIBLE_CASE, vars.map.map[y][x - 1]))
		return (1);
	if (vars.map.map[y][x - 1] == 'E'
		&& vars.collected == vars.map.nb_collec
		&& vars.killed >= vars.to_kill)
		return (1);
	else if (x > 2
		&& ft_strchr("Xx#b", vars.map.map[y][x - 1])
		&& ft_strchr("0B", vars.map.map[y][x - 2]))
		return (2);
	else if (x > 2 && ft_strchr("Xx#b", vars.map.map[y][x - 1])
		&& ft_strchr("RL", vars.map.map[y][x - 2])
		&& ft_strchr("bXDx#1", vars.map.map[y][x - 3]))
		return (3);
	return (0);
}

int	is_accessible(t_vars vars, int x, int y, int dir)
{
	if (dir == up)
		return (is_accessible_up(vars, x, y));
	else if (dir == down)
		return (is_accessible_down(vars, x, y));
	else if (dir == right)
		return (is_accessible_right(vars, x, y));
	else if (dir == left)
		return (is_accessible_left(vars, x, y));
	return (0);
}
