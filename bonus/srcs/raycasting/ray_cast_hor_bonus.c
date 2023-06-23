/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_hor_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:10:31 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 11:51:00 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	check_for_wall(t_cub *cub)
{
	if (cub->map[(int)((cub->ph_inter_y) / CARRE)][(int)((cub->ph_inter_x)
			/ CARRE)] == '1')
		return (1);
	else
	{
		cub->ph_inter_x += (cub->dh_x_ray);
		cub->ph_inter_y += (cub->dh_y_ray);
	}
	return (0);
}

int	ray_cast_hor(t_cub *cub)
{
	int	x;

	x = 0;
	if (cub->ph_inter_x <= 0)
	{
		cub->ph_inter_x = CARRE;
		x = 1;
	}
	else if (cub->ph_inter_x >= x_size(cub) * CARRE)
	{
		cub->ph_inter_x = x_size(cub) * CARRE - CARRE;
		x = 1;
	}
	if (cub->ph_inter_y >= (y_size(cub) * CARRE - CARRE))
	{
		cub->ph_inter_y = y_size(cub) * CARRE - CARRE;
		return (1);
	}
	if (x == 1)
		return (1);
	if (check_for_wall(cub) == 1)
		return (1);
	return (0);
}
