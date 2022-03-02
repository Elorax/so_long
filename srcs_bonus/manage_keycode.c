/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keycode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiersoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:27:18 by abiersoh          #+#    #+#             */
/*   Updated: 2021/12/21 01:47:05 by abiersoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	manage_keycode(t_vars *vars, int keycode, int x, int y)
{
	if (keycode == W_KEY || keycode == UP_KEY || keycode == Z_KEY)
		return (ft_check_up(vars, x, y));
	else if ((keycode == S_KEY || keycode == DOWN_KEY))
		return (ft_check_down(vars, x, y));
	else if ((keycode == D_KEY || keycode == RIGHT_KEY))
		return (ft_check_right(vars, x, y));
	else if ((keycode == A_KEY || keycode == Q_KEY || keycode == LEFT_KEY))
		return (ft_check_left(vars, x, y));
	return (1);
}
