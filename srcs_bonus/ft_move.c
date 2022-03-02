/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:52:41 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 19:15:27 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_print_data(t_vars *vars)
{
	char	*str;
	int		i;

	i = -1;
	while (++i < 4)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26],
			1300, 50 * i);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26],
			1350, 50 * i);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26],
			1400, 50 * i);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26],
			1450, 50 * i);
	}
	str = ft_itoa(vars->nb_moves);
	str = ft_strjoin2("Moves : ", str, 0, 1);
	mlx_string_put(vars->mlx, vars->win, 1400, 50,
		0x00FFFFFF, str);
	str = (free(str), ft_strjoin2("Niveau ", ft_itoa(vars->level), 0, 1));
	mlx_string_put(vars->mlx, vars->win, 1400, 200,
		0x00FFFFFF, str);
	(free(str), ft_print_data_ennemy(vars));
}

void	ft_print_life(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (i < vars->life)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->images[30], 1320 + i * 50, 300);
		else
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->images[31], 1320 + i * 50, 300);
	}
	if (vars->life > 10)
	{
		mlx_string_put(vars->mlx, vars->win, 1320, 600, 0x00FFFFFF,
			"IIIINFINIIITE POWEEEERR !!!");
		return ;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26], 1320, 550);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26], 1370, 550);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26], 1420, 550);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26], 1470, 550);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[26], 1520, 550);
}

void	ft_print_info(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 1320, 350, 0x00FFFFFF,
		"You have to complete every objective in the");
	mlx_string_put(vars->mlx, vars->win, 1320, 370, 0x00FFFFFF,
		"upper right corner before finishing level");
	mlx_string_put(vars->mlx, vars->win, 1320, 390, 0x00FFFFFF,
		"by joining your crabette");
	mlx_string_put(vars->mlx, vars->win, 1320, 410, 0x00FFFFFF,
		"Use either WASD or ZQSD or arrows for move");
	mlx_string_put(vars->mlx, vars->win, 1320, 430, 0x00FFFFFF,
		"Press Escape or click the red cross");
	mlx_string_put(vars->mlx, vars->win, 1320, 450, 0x00FFFFFF,
		"to quit game");
	mlx_string_put(vars->mlx, vars->win, 1320, 470, 0x00FFFFFF,
		"Press P for Pause");
	mlx_string_put(vars->mlx, vars->win, 1320, 490, 0x00FFFFFF,
		"Press R for Reset");
	mlx_string_put(vars->mlx, vars->win, 1320, 510, 0x00FFFFFF,
		"While in pause, type next for skip level");
	mlx_string_put(vars->mlx, vars->win, 1320, 530, 0x00FFFFFF,
		"And maybe you can type something else...");
	mlx_string_put(vars->mlx, vars->win, 1320, 550, 0x00FFFFFF,
		"To trigger some retro power");
}

void	ft_print_data_ennemy(t_vars *vars)
{
	char	*str;

	str = ft_strjoin2(ft_itoa(vars->collected), "/", 1, 0);
	str = ft_strjoin2(str, ft_itoa(vars->map.nb_collec), 1, 1);
	mlx_string_put(vars->mlx, vars->win, 1400, 100,
		0x00FFFFFF, str);
	free(str);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[28], 1430,
		100);
	if (vars->to_kill > 0)
	{
		str = ft_strjoin2(ft_itoa(vars->killed), "/", 1, 0);
		str = ft_strjoin2(str, ft_itoa(vars->to_kill), 1, 1);
		mlx_string_put(vars->mlx, vars->win, 1400,
			150, 0x00FFFFFF, str);
		free(str);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images[27], 1430,
			150);
	}
}

int	ft_move(t_vars *vars, int keycode)
{
	int		ret;

	ret = manage_keycode(vars, keycode, vars->x, vars->y);
	ft_print_data(vars);
	return (ret);
}
