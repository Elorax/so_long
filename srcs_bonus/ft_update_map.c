/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:08:02 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 08:32:19 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_put_img_classic(t_vars *vars, int index, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[index],
		j * vars->img_width, i * vars->img_height);
}

void	ft_put_img(t_vars *vars, int index, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[index],
		(j + vars->offset_x) * vars->img_width,
		(i + vars->offset_y) * vars->img_height);
}

void	affichage_full_map_p2(t_vars *vars, t_coordmax cmax, int i, int j)
{
	if (vars->map.map[i][j] == '1')
		ft_put_img(vars, 13, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'R')
		ft_put_img(vars, 14, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'L')
		ft_put_img(vars, 15, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'X')
		ft_put_img(vars, 16, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == '#')
		ft_put_img(vars, 17, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'x')
		ft_put_img(vars, 29, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'b')
		ft_put_img(vars, 18, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'B')
		ft_put_img(vars, 19, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'D')
		ft_put_img(vars, 20, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'd')
		ft_put_img(vars, 21, i - cmax.imin, j - cmax.jmin);
	if (vars->map.map[i][j] == 'q')
		ft_put_img(vars, 22 + vars->dir, i - cmax.imin, j - cmax.jmin);
}

void	ft_update_full_map(t_vars *vars)
{
	int			i;
	int			j;
	int			poissons;
	t_coordmax	cmax;

	(ft_calcul_offset_i(vars, &cmax), ft_calcul_offset_j(vars, &cmax));
	j = ((poissons = 0), (i = cmax.imin - 1), cmax.jmin - 1);
	while (++i <= cmax.imax)
	{
		while (++j <= cmax.jmax)
		{
			if (vars->map.map[i][j] == '0')
				ft_put_img(vars, vars->frames % 4,
					i - cmax.imin, j - cmax.jmin);
			if (vars->map.map[i][j] == 'C')
				ft_put_img(vars, 4 + (vars->frames + ++poissons) % 4,
					i - cmax.imin, j - cmax.jmin);
			if (ft_strchr("Pp", vars->map.map[i][j]))
				ft_put_img(vars, 8 + vars->dir, i - cmax.imin, j - cmax.jmin);
			if (vars->map.map[i][j] == 'E')
				ft_put_img(vars, 12, i - cmax.imin, j - cmax.jmin);
			affichage_full_map_p2(vars, cmax, i, j);
		}
		j = cmax.jmin - 1;
	}
}
