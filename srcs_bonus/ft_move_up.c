/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:50:14 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/29 10:50:15 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	check_state2(t_vars *vars, int x, int y)
{
	if (vars->map.map[y - 2][x] == 'B'
		&& ft_strchr("#x", vars->map.map[y - 1][x]))
		vars->map.map[y - 2][x] = 'x';
	if (vars->map.map[y - 2][x] == 'B'
		&& ft_strchr("bX", vars->map.map[y - 1][x]))
		vars->map.map[y - 2][x] = 'b';
	if (vars->map.map[y - 2][x] == '0'
		&& ft_strchr("#x", vars->map.map[y - 1][x]))
		vars->map.map[y - 2][x] = '#';
	if (vars->map.map[y - 2][x] == '0'
		&& ft_strchr("bX", vars->map.map[y - 1][x]))
		vars->map.map[y - 2][x] = 'X';
	check_doors(vars);
}

int	ft_check_up(t_vars *vars, int x, int y)
{
	int	state;

	vars->dir = up;
	state = is_accessible(*vars, x, y, vars->dir);
	vars->nb_moves += (state > 0);
	vars->collected += (vars->map.map[y - 1][x] == 'C');
	if (state == 1)
	{
		if (ft_strchr("RL", vars->map.map[y - 1][x]))
			return (0);
		if (vars->map.map[y - 1][x] == 'E')
			return (-1);
	}
	else if (state == 2)
	{
		check_state2(vars, x, y);
	}
	else if (state == 3)
		vars->map.map[y - 2][x] = (vars->killed++, '#');
	if (state > 0)
		ft_move_up(vars, x, y);
	return (1);
}

void	ft_move_up(t_vars *vars, int x, int y)
{
	int	doors;

	doors = 0;
	(vars->y)--;
	if (vars->map.map[y][x] == 'P')
		vars->map.map[y][x] = '0';
	if (vars->map.map[y][x] == 'p')
	{
		vars->map.map[y][x] = 'B';
		doors = 1;
	}
	if (vars->map.map[y][x] == 'q')
		vars->map.map[y][x] = (doors++, 'd');
	if (ft_strchr("0#XC", vars->map.map[y - 1][x]))
		vars->map.map[y - 1][x] = 'P';
	if (ft_strchr("Bbx", vars->map.map[y - 1][x]))
	{
		vars->map.map[y - 1][x] = 'p';
		doors = 1;
	}
	if (vars->map.map[y - 1][x] == 'd')
		vars->map.map[y - 1][x] = (doors++, 'q');
	if (doors)
		check_doors(vars);
}
