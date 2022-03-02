/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:10:20 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 18:56:29 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_fondu(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= WHEIGHT + 10)
	{
		j = -1;
		while (++j < WLENGTH - 300)
		{
			mlx_pixel_put(vars->mlx, vars->win, j, i, 0);
		}
		usleep(1000);
	}
	usleep(300000);
}

void	ft_put_pixel_horizontal(t_vars *vars, int y)
{
	int	j;

	j = -1;
	while (++j < WLENGTH - 300)
		mlx_pixel_put(vars->mlx, vars->win, j, y, 0);
}

void	ft_put_pixel_vertical(t_vars *vars, int x)
{
	int	i;

	i = -1;
	while (++i < WHEIGHT)
		mlx_pixel_put(vars->mlx, vars->win, x, i, 0);
}

void	ft_mega_fondu(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= WHEIGHT + 10)
	{
		j = 1300;
		while (++j < WLENGTH)
		{
			mlx_pixel_put(vars->mlx, vars->win, j, i, 0);
		}
		usleep(500);
	}
	usleep(400000);
	j = -1;
	while (++j < 650)
	{
		ft_put_pixel_horizontal(vars, (j * 900) / 1300);
		ft_put_pixel_vertical(vars, 1300 - j);
		ft_put_pixel_horizontal(vars, 900 - (j * 900) / 1300);
		ft_put_pixel_vertical(vars, j);
		usleep(1000);
	}
	usleep(100000);
}
