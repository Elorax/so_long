/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:29:00 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/18 16:33:16 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_vars(t_vars *vars)
{
	vars->map.length = 0;
	vars->map.height = 0;
	vars->map.nb_exit = 0;
	vars->map.nb_collec = 0;
	vars->map.nb_player = 0;
	vars->map.fd = 0;
	vars->collected = 0;
	vars->nb_moves = 0;
}

void	*read_image(t_vars *vars, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, path,
			&vars->img_width, &vars->img_height);
	return (img);
}

void	**ft_init_images(t_vars *vars)
{
	void	**images;

	images = malloc(sizeof(*images) * 6);
	if (!images)
		return (NULL);
	images[0] = read_image(vars, "img50/Sol1.xpm");
	images[1] = read_image(vars, "img50/Collectible1.xpm");
	images[2] = read_image(vars, "img50/Personnage1.xpm");
	images[3] = read_image(vars, "img50/Exit1.xpm");
	images[4] = read_image(vars, "img50/Obstacle1.xpm");
	images[5] = NULL;
	return (images);
}

int	ft_init_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!(map->map))
		return (-1);
	map->map[i] = get_next_line(map->fd);
	while (map->map[i])
	{
		printf("%s", map->map[i]);
		if (ft_check_line(map, i) != 0)
			return (printf("Erreur : Mauvaise map.\n"), -1);
		if (i > 0 && ft_strlen(map->map[i]) != ft_strlen(map->map[i - 1]))
			return (printf("Erreur : Mauvaise map.\n"), -1);
		i++;
		map->map[i] = get_next_line(map->fd);
	}
	if ((i > 1) && (ft_check_first_line(map->map[0])
			|| ft_check_first_line(map->map[i - 1])))
		return (printf("Erreur : Mauvaise map.\n"), -1);
	if (map->nb_player != 1 || map->nb_exit != 1 || map->nb_collec < 1)
		return (printf("Erreur : Mauvaise map.\n"), -1);
	map->height = i;
	map->length = ft_strlen(map->map[0]) - 1;
	return (0);
}
