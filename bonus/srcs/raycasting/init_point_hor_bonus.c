/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point_hor_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:13:01 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	init_point_inter_hor(t_cub *cub)
{
	if (cub->ray_dir > deg_to_rad(0) && cub->ray_dir < deg_to_rad(180))
	{
		cub->ph_inter_y = floor(cub->ply.pixel_y / CARRE) * CARRE + CARRE;
		cub->dh_y_ray = CARRE;
	}
	else
	{
		cub->ph_inter_y = floor(cub->ply.pixel_y / CARRE) * CARRE - 0.000001;
		cub->dh_y_ray = -CARRE;
	}
	if (cub->ray_dir >= deg_to_rad(90) && cub->ray_dir <= deg_to_rad(270))
		cub->ph_inter_x = (cub->ply.pixel_x - fabs((cub->ply.pixel_y
						- cub->ph_inter_y) / (tan(cub->ray_dir))));
	else
		cub->ph_inter_x = (cub->ply.pixel_x + fabs((cub->ply.pixel_y
						- cub->ph_inter_y) / (tan(cub->ray_dir))));
	cub->dh_x_ray = (fabs(CARRE / (tan(cub->ray_dir))));
	if (cub->ray_dir > deg_to_rad(90) && cub->ray_dir < deg_to_rad(270))
		cub->dh_x_ray *= -1;
}
