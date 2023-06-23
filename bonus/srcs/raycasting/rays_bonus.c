/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:03:12 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 12:57:05 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	horizontal(t_cub *cub, int col)
{
	if (cub->ray_dir == cub->ply.dir)
		cub->friction = 1;
	if (cub->ray_dir >= deg_to_rad(180) && cub->ray_dir <= deg_to_rad(360))
		draw_wal(cub, 'H', col, 'T');
	else
		draw_wal(cub, 'H', col, 'B');
	if (cub->ray_dir == cub->ply.dir && cub->map[(int)cub->ph_inter_y
		/ CARRE][(int)cub->ph_inter_x / CARRE] == '2')
	{
		cub->x_midle_ray = cub->ph_inter_x;
		cub->y_midle_ray = cub->ph_inter_y;
	}
}

void	vertical(t_cub *cub, int col)
{
	if (cub->ray_dir == cub->ply.dir)
		cub->friction = 2;
	if (cub->ray_dir >= deg_to_rad(90) && cub->ray_dir <= deg_to_rad(270))
		draw_wal(cub, 'V', col, 'L');
	else
		draw_wal(cub, 'V', col, 'R');
	if (cub->ray_dir == cub->ply.dir && cub->map[(int)cub->pv_inter_y
		/ CARRE][(int)cub->pv_inter_x / CARRE] == '2')
	{
		cub->x_midle_ray = cub->pv_inter_x;
		cub->y_midle_ray = cub->pv_inter_y;
	}
}

void	rays(t_cub *cub)
{
	int	col;
	int	check_ray;

	col = 0;
	find_first_ray(cub);
	while (col < WIDTH)
	{
		check_ray = ray_casting(cub);
		if (check_ray == 100)
			vertical(cub, col);
		else if (check_ray == 200)
			horizontal(cub, col);
		cub->ray_dir += ((M_PI / 3) / WIDTH);
		if (cub->ray_dir > 2 * M_PI)
			cub->ray_dir = 0;
		col++;
	}
}
