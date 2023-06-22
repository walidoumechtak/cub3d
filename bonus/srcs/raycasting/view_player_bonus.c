/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:32:59 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/19 15:31:03 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	view_of_player(t_cub *cub, int key)
{
	cub->map[cub->ply.yp][cub->ply.xp] = 'Z';
	if (key == 123)
	{
		cub->ply.dir = cub->ply.dir - deg_to_rad(R_VIEW);
		if (cub->ply.dir <= 0)
			cub->ply.dir = 2 * M_PI;
	}
	else if (key == 124)
	{
		cub->ply.dir = cub->ply.dir + deg_to_rad(R_VIEW);
		if (cub->ply.dir > 2 * M_PI)
			cub->ply.dir = 0;
	}
	cub->ply.end_xline = MINI_SIZE + 3 + (cos(cub->ply.dir) * (25));
	cub->ply.end_yline = MINI_SIZE + 3 + (sin(cub->ply.dir) * (25));
}
