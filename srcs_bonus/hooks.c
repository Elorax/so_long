/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:38:34 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 19:13:30 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../so_long_bonus.h"

int	exit_hook(t_vars *vars)
{
	ft_mlx_close_croix_rouge_de_ses_morts(vars);
	return (0);
}

void	manage_movement(t_vars *vars, int keycode)
{
	int	i;

	i = ft_move(vars, keycode);
	if (i == 1)
		ft_update_full_map(vars);
	else if (i == 0)
	{
		if (--vars->life >= 0)
			ft_mlx_restart(vars);
		else
			ft_mlx_close_game(vars);
	}
	else
	{
		printf("Moves : %d\n", vars->nb_moves);
		printf("Best moves possible : %s", vars->objectif);
		if (vars->av[vars->level + 1])
			ft_next_level(vars);
		else
			ft_mlx_close_game(vars);
	}
}

void	handle_cheatcode(t_vars *vars, int keycode)
{
	static int	koko = 0;

	if (keycode == UP_KEY && koko < 2)
		koko++;
	else if (keycode == DOWN_KEY && koko > 1 && koko < 4)
		koko++;
	else if (keycode == LEFT_KEY && (koko == 4 || koko == 6))
		koko++;
	else if (keycode == RIGHT_KEY && (koko == 5 || koko == 7))
		koko++;
	else if (keycode == 'b' && koko == 8)
		koko++;
	else if (keycode == 'a' && koko == 9)
		koko++;
	else
		koko = 0;
	if (koko == 10)
	{
		if (vars->life < 10)
			vars->life = 123456789;
		else
			vars->life = 5;
		ft_print_life(vars);
		vars->koko = !vars->koko;
	}
}

void	handle_next(t_vars *vars, int keycode)
{
	static int	next = 0;

	if (keycode == 'n' && !next)
		next++;
	else if (keycode == 'e' && next == 1)
		next++;
	else if (keycode == 'x' && next == 2)
		next++;
	else if (keycode == 't' && next == 3)
		next++;
	else
		next = 0;
	if (next == 4)
	{
		next = 0;
		vars->pause = 0;
		if (vars->av[vars->level + 1])
			ft_next_level(vars);
		else
			ft_mlx_close_game(vars);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE_KEY)
		ft_mlx_close_game(vars);
	else if (keycode == P_KEY)
		vars->pause = !vars->pause;
	if (vars->pause)
		return (handle_cheatcode(vars, keycode), handle_next(vars, keycode), 0);
	else if (keycode == R_KEY)
	{
		if (--vars->life >= 0)
			ft_mlx_restart(vars);
		else
			ft_mlx_close_game(vars);
	}
	else if (keycode == 'l')
		vars->life = 5;
	else if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
		|| keycode == D_KEY || keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == RIGHT_KEY || keycode == LEFT_KEY
		|| keycode == Z_KEY || keycode == Q_KEY)
		manage_movement(vars, keycode);
	return (keycode);
}
