/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:08:33 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

double	calcdistance(t_cub *cub, double x, double y)
{
	return (sqrt(pow(x - cub->ply.pixel_x, 2) + pow(y - cub->ply.pixel_y, 2)));
}

int	ray_casting(t_cub *cub)
{
	int	check_v;
	int	check_h;

	init_point_inter_hor(cub);
	init_point_inter_ver(cub);
	check_v = 100;
	check_h = 200;
	while (1)
	{
		cub->dis_v = calcdistance(cub, cub->pv_inter_x, cub->pv_inter_y);
		cub->dis_h = calcdistance(cub, cub->ph_inter_x, cub->ph_inter_y);
		if (cub->dis_v < cub->dis_h)
		{
			if (ray_cast_ver(cub) == 1)
				return (check_v);
		}
		else
		{
			if (ray_cast_hor(cub) == 1)
				return (check_h);
		}
	}
	return (0);
}
