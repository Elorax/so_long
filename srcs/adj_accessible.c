/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_accessible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:01:03 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 16:20:12 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_adjacent(t_vars *vars, int y, int x)
{
	if (!x || !y || x == vars->map.length - 1 || y == vars->map.height - 1)
		return (0);
	if (vars->map.map[y][x] == 'P')
		return (1);
	if (vars->map.map[y - 1][x] == 'P')
		return (1);
	if (vars->map.map[y + 1][x] == 'P')
		return (1);
	if (vars->map.map[y][x - 1] == 'P')
		return (1);
	if (vars->map.map[y][x + 1] == 'P')
		return (1);
	return (0);
}

void	get_coords(t_vars *vars, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	*x = 0;
	*y = 0;
}

int	is_accessible(char c, t_vars vars)
{
	if (c == '1' || (c == 'E' && vars.collected != vars.map.nb_collec))
		return (0);
	return (1);
}
