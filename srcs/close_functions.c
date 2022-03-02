/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:10:20 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 16:23:24 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_mlx_close_escape(t_vars *vars)
{
	t_xvar	*ptr;

	if (vars->win)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
		ptr = (t_xvar *)(vars->mlx);
		ptr->end_loop = 1;
	}
	printf("Collectibles : %d / %d\n", vars->collected, vars->map.nb_collec);
	printf("Moooooooves : %d\n", vars->nb_moves);
}

void	ft_mlx_close_croix_rouge_de_ses_morts(t_vars *vars)
{
	t_xvar	*ptr;

	if (vars->win != NULL)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
		ptr = (t_xvar *)(vars->mlx);
		ptr->end_loop = 1;
	}
	printf("Collectibles : %d / %d\n", vars->collected, vars->map.nb_collec);
	printf("Moooooooooves : %d\n", vars->nb_moves);
}
