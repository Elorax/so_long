/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:07:28 by abiersoh          #+#    #+#             */
/*   Updated: 2022/03/06 15:54:54 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_play(t_vars *vars)
{
	vars->level = 1;
	vars->map.path = ft_strdup(vars->av[vars->level]);
	ft_init_vars(vars);
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	vars->map.height = ft_count_lines(vars->map);
	close(vars->map.fd);
	vars->map.fd = open(vars->av[vars->level], O_RDONLY);
	if (ft_init_map(&(vars->map)) == -1)
	{
		ft_delete_vars(vars);//Attention peut etre free des trucs pas alloues
		return (0);
	}
	close(vars->map.fd);
	ft_begin_game(vars);
	ft_delete_vars(vars);
	return (0);
}

int	check_argument(char *av, t_vars *vars)
{
	int	j;

	j = -1;
	if (!is_name_valid(av))
		return (printf("%s : filename not valid\n", av), 0);
	vars->map.fd = open(av, O_RDONLY);
	if (vars->map.fd <= 0)
		return (printf("Cannot open file %s\n", av), 0);
	vars->map.height = ft_count_lines(vars->map);
	close(vars->map.fd);
	vars->map.fd = open(av, O_RDONLY);
	if (ft_init_map(&(vars->map)) == -1)
	{
		while (vars->map.map[++j])
			free(vars->map.map[j]);
		free(vars->map.map);
		return (printf("%s : invalid map\n", av), 0);
	}
	close(vars->map.fd);
	while (vars->map.map[++j])
		free(vars->map.map[j]);
	free(vars->map.map);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		i;

	i = 0;
	if (ac < 2)
		return (printf("No arguments\n"), -1);
	vars.av = av;
	while (av[++i])
		if (check_argument(av[i], &vars) == 0)
			return (0);
	ft_play(&vars);
}
