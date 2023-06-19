/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:03:12 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/19 14:33:41 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ray_checker(t_cub *cub, int columun, int check_ray)
{
	if (check_ray == 100)
	{
		if (cub->ray_dir >= deg_to_rad(90) && cub->ray_dir <= deg_to_rad(270))
			draw_wal(cub, 'V', columun, 'L');
		else
			draw_wal(cub, 'V', columun, 'R');
	}
	else if (check_ray == 200)
	{
		if (cub->ray_dir >= deg_to_rad(180) && cub->ray_dir <= deg_to_rad(360))
			draw_wal(cub, 'H', columun, 'T');
		else
			draw_wal(cub, 'H', columun, 'B');
	}
}

void	rays(t_cub *cub)
{
	int	columun;
	int	check_ray;

	columun = 0;
	find_first_ray(cub);
	while (columun < WIDTH)
	{
		check_ray = ray_casting(cub);
		ray_checker(cub, columun, check_ray);
		cub->ray_dir += ((M_PI / 3) / WIDTH);
		if (cub->ray_dir > 2 * M_PI)
			cub->ray_dir = 0;
		columun++;
	}
}
