/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:29:00 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/29 10:50:39 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	*read_image(t_vars *vars, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, path,
			&vars->img_width, &vars->img_height);
	return (img);
}

void	ft_init_images_p2(void **images, t_vars *vars)
{
	images[14] = read_image(vars, "img/Poulpyright.xpm");
	images[15] = read_image(vars, "img/Poulpyleft.xpm");
	images[16] = read_image(vars, "img/Moveable.xpm");
	images[17] = read_image(vars, "img/Dead.xpm");
	images[18] = read_image(vars, "img/Moveable_Placed.xpm");
	images[19] = read_image(vars, "img/Brown_Cross.xpm");
	images[20] = read_image(vars, "img/Closed_Door.xpm");
	images[21] = read_image(vars, "img/Open_Door.xpm");
	images[22] = read_image(vars, "img/Personnage_Door1.xpm");
	images[23] = read_image(vars, "img/Personnage_Door2.xpm");
	images[24] = read_image(vars, "img/Personnage_Door3.xpm");
	images[25] = read_image(vars, "img/Personnage_Door4.xpm");
	images[26] = read_image(vars, "img/Void.xpm");
	images[29] = read_image(vars, "img/Dead.xpm");
	images[32] = NULL;
}

void	**ft_init_images(t_vars *vars)
{
	void	**images;

	images = malloc(sizeof(*images) * 33);
	if (!images)
		return (NULL);
	images[27] = read_image(vars, "img/MiniPoulpy.xpm");
	images[28] = read_image(vars, "img/MiniFish.xpm");
	images[30] = read_image(vars, "img/full_heart.xpm");
	images[31] = read_image(vars, "img/empty_heart.xpm");
	images[0] = read_image(vars, "img/Sol1.xpm");
	images[1] = read_image(vars, "img/Sol2.xpm");
	images[2] = read_image(vars, "img/Sol3.xpm");
	images[3] = read_image(vars, "img/Sol4.xpm");
	images[4] = read_image(vars, "img/Collectible1.xpm");
	images[5] = read_image(vars, "img/Collectible2.xpm");
	images[6] = read_image(vars, "img/Collectible3.xpm");
	images[7] = read_image(vars, "img/Collectible4.xpm");
	images[8] = read_image(vars, "img/Personnage1.xpm");
	images[9] = read_image(vars, "img/Personnage2.xpm");
	images[10] = read_image(vars, "img/Personnage3.xpm");
	images[11] = read_image(vars, "img/Personnage4.xpm");
	images[12] = read_image(vars, "img/Exit1.xpm");
	images[13] = read_image(vars, "img/Obstacle1.xpm");
	ft_init_images_p2(images, vars);
	return (images);
}
