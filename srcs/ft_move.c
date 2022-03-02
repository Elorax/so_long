/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:27:18 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 16:33:45 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move_up(t_vars *vars, int x, int y)
{
	if (is_accessible(vars->map.map[y - 1][x], *vars))
	{
		vars->collected += (vars->map.map[y - 1][x] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y - 1][x] == 'E')
			return (0);
		vars->map.map[y][x] = '0';
		vars->map.map[y - 1][x] = 'P';
		printf("Collectibles : %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves : %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_down(t_vars *vars, int x, int y)
{
	if (is_accessible(vars->map.map[y + 1][x], *vars))
	{
		vars->collected += (vars->map.map[y + 1][x] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y + 1][x] == 'E')
			return (0);
		vars->map.map[y][x] = '0';
		vars->map.map[y + 1][x] = 'P';
		printf("Collectibles : %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves : %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_right(t_vars *vars, int x, int y)
{
	if (is_accessible(vars->map.map[y][x + 1], *vars))
	{
		vars->collected += (vars->map.map[y][x + 1] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y][x + 1] == 'E')
			return (0);
		vars->map.map[y][x] = '0';
		vars->map.map[y][x + 1] = 'P';
		printf("Collectibles : %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves : %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move_left(t_vars *vars, int x, int y)
{
	if (is_accessible(vars->map.map[y][x - 1], *vars))
	{
		vars->collected += (vars->map.map[y][x - 1] == 'C');
		vars->nb_moves++;
		if (vars->map.map[y][x - 1] == 'E')
			return (0);
		vars->map.map[y][x] = '0';
		vars->map.map[y][x - 1] = 'P';
		printf("Collectibles : %d / %d\n", vars->collected, vars->map.nb_collec);
		printf("Moves : %d\n", vars->nb_moves);
	}
	return (1);
}

int	ft_move(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	get_coords(vars, &x, &y);
	return (manage_keycode(vars, keycode, x, y));
}
