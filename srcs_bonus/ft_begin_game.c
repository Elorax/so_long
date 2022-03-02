/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:17:02 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/30 18:31:53 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_print_case(t_vars *vars, char c, int i, int j)
{
	if (c == '0')
		ft_put_img(vars, 0, i, j);
	else if (c == 'C')
		ft_put_img(vars, 4, i, j);
	else if (c == 'P')
		ft_put_img(vars, 8, i, j);
	else if (c == 'E')
		ft_put_img(vars, 12, i, j);
	else if (c == '1')
		ft_put_img(vars, 13, i, j);
	else if (c == 'R')
		ft_put_img(vars, 14, i, j);
	else if (c == 'L')
		ft_put_img(vars, 15, i, j);
	else if (c == 'X')
		ft_put_img(vars, 16, i, j);
	else if (c == 'B')
		ft_put_img(vars, 19, i, j);
	else if (c == 'b')
		ft_put_img(vars, 18, i, j);
	else if (c == 'D')
		ft_put_img(vars, 20, i, j);
}

void	ft_display_map(t_vars *vars)
{
	int			i;
	int			j;
	t_coordmax	cmax;

	ft_calcul_offset_i(vars, &cmax);
	ft_calcul_offset_j(vars, &cmax);
	i = cmax.imin -1;
	j = cmax.jmin -1;
	while (++i <= cmax.imax)
	{
		while (++j <= cmax.jmax)
		{
			ft_print_case(vars, vars->map.map[i][j],
				i - cmax.imin, j - cmax.jmin);
		}
		j = cmax.jmin - 1;
	}
}

void	ft_setup_hooks(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, &handle_no_event, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, exit_hook, vars);
}

void	ft_begin_level(t_vars *vars)
{
	if (!vars->av[vars->level])
		ft_mlx_close_game(vars);
	ft_init_vars(vars);
	if (vars->life < 5)
		vars->life++;
	ft_print_life(vars);
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	if (vars->map.fd <= 0)
	{
		printf("Error while opening arg number %d\n", vars->level);
		return ;
	}
	vars->map.height = ft_count_lines(vars->map);
	close(vars->map.fd);
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	if (ft_init_map(&(vars->map)) == -1)
		return ;
	close(vars->map.fd);
	ft_fill_coraux_bizarres(vars);
	get_coords(vars, &(vars->x), &(vars->y));
	ft_calcul_decalage(vars, &(vars->offset_x), &(vars->offset_y));
	ft_display_map(vars);
	check_doors(vars);
	ft_print_data(vars);
}

void	ft_begin_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WLENGTH,
			WHEIGHT, "Thanks for all the fish !");
	vars->images = ft_init_images(vars);
	ft_fill_coraux_bizarres(vars);
	get_coords(vars, &(vars->x), &(vars->y));
	ft_calcul_decalage(vars, &(vars->offset_x), &(vars->offset_y));
	ft_display_map(vars);
	check_doors(vars);
	vars->life = 5;
	ft_print_data(vars);
	ft_print_life(vars);
	ft_setup_hooks(vars);
	ft_print_info(vars);
	mlx_loop(vars->mlx);
}
