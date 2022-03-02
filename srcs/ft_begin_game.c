/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:17:02 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 16:21:20 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//malloc qui petent a gerer !!

void	ft_display_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (vars->map.map[++i])
	{
		while (vars->map.map[i][++j])
		{
			if (vars->map.map[i][j] == '0')
				ft_put_img(vars, 0, i, j);
			if (vars->map.map[i][j] == '1')
				ft_put_img(vars, 4, i, j);
			if (vars->map.map[i][j] == 'E')
				ft_put_img(vars, 3, i, j);
			if (vars->map.map[i][j] == 'P')
				ft_put_img(vars, 2, i, j);
			if (vars->map.map[i][j] == 'C')
				ft_put_img(vars, 1, i, j);
		}
		j = -1;
	}
}

void	ft_setup_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, exit_hook, vars);
}

void	ft_begin_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 50 * vars->map.length,
			50 * vars->map.height, "Thanks for all the fish !");
	vars->images = ft_init_images(vars);
	ft_display_map(vars);
	ft_setup_hooks(vars);
	mlx_loop(vars->mlx);
}
