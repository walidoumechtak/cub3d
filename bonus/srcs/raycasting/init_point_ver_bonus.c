/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point_ver_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:11:50 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	init_point_inter_ver(t_cub *cub)
{
	if (cub->ray_dir > deg_to_rad(90) && cub->ray_dir < deg_to_rad(270))
	{
		cub->pv_inter_x = floor(cub->ply.pixel_x / CARRE) * CARRE - 0.000001;
		cub->dv_x_ray = -CARRE;
	}
	else
	{
		cub->pv_inter_x = floor(cub->ply.pixel_x / CARRE) * CARRE + CARRE;
		cub->dv_x_ray = CARRE;
	}
	if (cub->ray_dir >= deg_to_rad(0) && cub->ray_dir <= deg_to_rad(180))
		cub->pv_inter_y = (cub->ply.pixel_y + fabs((cub->ply.pixel_x
						- cub->pv_inter_x) * (tan(cub->ray_dir))));
	else
		cub->pv_inter_y = (cub->ply.pixel_y - fabs((cub->ply.pixel_x
						- cub->pv_inter_x) * (tan(cub->ray_dir))));
	cub->dv_y_ray = (fabs(tan(cub->ray_dir) * CARRE));
	if (cub->ray_dir > deg_to_rad(180) && cub->ray_dir < deg_to_rad(360))
		cub->dv_y_ray *= -1;
}
