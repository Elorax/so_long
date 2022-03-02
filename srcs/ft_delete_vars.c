/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:30:49 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 14:32:32 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_delete_vars(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map.map[++i])
		free(vars->map.map[i]);
	free(vars->map.map);
	i = -1;
	while (vars->images[++i])
		mlx_destroy_image(vars->mlx, vars->images[i]);
	free(vars->images);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}
