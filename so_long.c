/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:07:28 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 16:26:08 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_play(t_vars *vars, char *av, int index)
{
	if (!is_name_valid(av))
		return (-1);
	ft_init_vars(vars);
	vars->map.fd = open(av, O_RDONLY);
	if (vars->map.fd <= 0)
	{
		printf("Erreur lors de l'ouverture du fichier de l'arg %d\n", index);
		return (-1);
	}
	vars->map.height = ft_count_lines(vars->map);
	close(vars->map.fd);
	vars->map.fd = open(av, O_RDONLY);
	if (ft_init_map(&(vars->map)) == -1)
		return (-1);//Attention a tout free
	printf("Argument %d : Map valide !\n", index);
	close(vars->map.fd);
	printf("Coucou\n");
	ft_begin_game(vars);
	ft_delete_vars(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		return (printf("Please enter exactly one map.\n"), -1);
	if (ft_play(&vars, av[1], 1) == -1)
	{
	}
}
