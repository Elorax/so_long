/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:52:53 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 07:11:02 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_animate_map(t_vars *vars)
{
	int			i;
	int			j;
	int			poissons;
	t_coordmax	cmx;

	(ft_calcul_offset_i(vars, &cmx), ft_calcul_offset_j(vars, &cmx));
	i = ((j = cmx.jmin - 1), (poissons = 0), vars->frames++, cmx.imin - 1);
	if (!(vars->frames % 2) && ft_pat_patrouille(vars) == -1)
		return ;
	while (++i <= cmx.imax)
	{
		while (++j <= cmx.jmax)
		{
			if (vars->map.map[i][j] == '0')
				ft_put_img(vars, vars->frames % 4, i - cmx.imin, j - cmx.jmin);
			else if (vars->map.map[i][j] == 'C')
				ft_put_img(vars, 4 + ((vars->frames + ++poissons) % 4),
					i - cmx.imin, j - cmx.jmin);
			else if (vars->map.map[i][j] == 'R')
				ft_put_img(vars, 14, i - cmx.imin, j - cmx.jmin);
			else if (vars->map.map[i][j] == 'L')
				ft_put_img(vars, 15, i - cmx.imin, j - cmx.jmin);
		}
		j = cmx.jmin - 1;
	}
}
