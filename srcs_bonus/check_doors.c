/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:28:42 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 07:12:45 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_update_doors(t_vars *vars)
{
	int			i;
	int			j;
	t_coordmax	cmax;

	ft_calcul_offset_i(vars, &cmax);
	ft_calcul_offset_j(vars, &cmax);
	i = cmax.imin - 1;
	j = cmax.jmin - 1;
	while (++i <= cmax.imax)
	{
		while (++j <= cmax.jmax)
		{
			if (vars->map.map[i][j] == 'D')
				ft_put_img(vars, 20, i - cmax.imin, j - cmax.jmin);
			if (vars->map.map[i][j] == 'd')
				ft_put_img(vars, 21, i - cmax.imin, j - cmax.jmin);
		}
		j = cmax.jmin -1;
	}
}

void	open_doors(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map.map[++i])
	{
		while (vars->map.map[i][++j])
			if (vars->map.map[i][j] == 'D')
				vars->map.map[i][j] = 'd';
		j = 0;
	}
}

void	close_doors(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map.map[++i])
	{
		while (vars->map.map[i][++j])
			if (vars->map.map[i][j] == 'd')
				vars->map.map[i][j] = 'D';
		j = 0;
	}
}

void	check_doors(t_vars *vars)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (vars->map.map[++i])
	{
		while (vars->map.map[i][++j])
		{
			if (ft_strchr("B", vars->map.map[i][j]))
				tmp = 1;
		}
		j = 0;
	}
	if (!tmp)
		open_doors(vars);
	else if (tmp == 1)
		close_doors(vars);
	ft_update_doors(vars);
}
