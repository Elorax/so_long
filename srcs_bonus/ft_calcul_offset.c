/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 06:40:54 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 08:54:54 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_calcul_decalage(t_vars *vars, int *offset_x, int *offset_y)
{
	*offset_x = max(0, ((WLENGTH - 300) / TILE_SIZE) - vars->map.length);
	*offset_y = max(0, (WHEIGHT / TILE_SIZE) - vars->map.height);
	*offset_x /= 2;
	*offset_y /= 2;
}

void	ft_calcul_offset_i(t_vars *vars, t_coordmax *cmax)
{
	if (vars->y < ((WHEIGHT / TILE_SIZE) + 1) / 2)
	{
		cmax->imin = 0;
		cmax->imax = min((WHEIGHT / TILE_SIZE) - 1, vars->map.height - 1);
	}
	else if (vars->y > vars->map.height - (((WHEIGHT / TILE_SIZE) + 1) / 2))
	{
		cmax->imin = max(0, vars->map.height - ((WHEIGHT / TILE_SIZE)));
		cmax->imax = vars->map.height - 1;
	}
	else
	{
		cmax->imin = max(0, vars->y - (((WHEIGHT / TILE_SIZE)) / 2));
		cmax->imax = min(vars->map.height - 1,
				vars->y + ((WHEIGHT / TILE_SIZE) / 2));
	}
}

void	ft_calcul_offset_j(t_vars *vars, t_coordmax *cmax)
{
	if (vars->x < (((WLENGTH - 300) / TILE_SIZE) + 1) / 2)
	{
		cmax->jmin = 0;
		cmax->jmax = min(((WLENGTH - 300) / TILE_SIZE - 1),
				vars->map.length - 1);
	}
	else if (vars->x > vars->map.length
		- ((((WLENGTH - 300) / TILE_SIZE) + 1) / 2))
	{
		cmax->jmin = max(0, vars->map.length - ((WLENGTH - 300) / TILE_SIZE));
		cmax->jmax = vars->map.length - 1;
	}
	else
	{
		cmax->jmin = max(0, vars->x - (((WLENGTH - 300) / TILE_SIZE) / 2));
		cmax->jmax = min(vars->map.length - 1,
				vars->x + (((WLENGTH - 300) / TILE_SIZE) / 2));
	}
}
