/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:13:59 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

// w = 13, a = 0, s = 1, d = 2

void	movement(t_cub *cub, int key)
{
	double	rot;

	rot = 0;
	if (key == 13 || key == 126)
	{
		cub->ply.dir_vec = 1;
	}
	else if (key == 1 || key == 125)
	{
		cub->ply.dir_vec = -1;
	}
	else if (key == 0)
	{
		cub->ply.dir_vec = -1;
		rot = deg_to_rad(90);
	}
	else if (key == 2)
	{
		cub->ply.dir_vec = 1;
		rot = deg_to_rad(90);
	}
	move_player(cub, rot);
}
