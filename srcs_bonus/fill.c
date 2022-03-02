/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:48:54 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/29 10:48:56 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_fill_coraux_bizarres(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < WHEIGHT / TILE_SIZE)
	{
		while (++j < (WLENGTH - 300) / TILE_SIZE)
			ft_put_img_classic(vars, 0, i, j);
		j = -1;
	}
}
