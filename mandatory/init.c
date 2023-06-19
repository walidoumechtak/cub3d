/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:22:31 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/19 13:33:58 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	get_player_cord(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E'
				|| cub->map[i][j] == 'S' || cub->map[i][j] == 'W')
			{
				cub->ply.xp = j;
				cub->ply.yp = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_str(t_cub *cub)
{
	get_player_cord(cub);
	cub->ply.pixel_x = cub->ply.xp * CARRE;
	cub->ply.pixel_y = cub->ply.yp * CARRE;
	cub->ply.move_speed = 3;
	cub->ply.dir_vec = 0;
	cub->is_wall = 0;
	if (cub->map[cub->ply.yp][cub->ply.xp] == 'N')
		cub->ply.dir = deg_to_rad(270);
	cub->ply.fov = deg_to_rad(60);
	cub->ray_dir = (cub->ply.dir - (deg_to_rad(30)));
	cub->dis_proj_plan = (WIDTH / 2) / tan(deg_to_rad(30));
	cub->dis_h = 0;
	cub->dis_v = 0;
	cub->ply.end_xline = 63 + (cos(cub->ply.dir) * (25));
	cub->ply.end_yline = 63 + (sin(cub->ply.dir) * (25));
	cub->no_ptr = mlx_xpm_file_to_image(cub->mlx, cub->no,
			&cub->tex_size.no_width, &cub->tex_size.no_height);
	cub->ea_ptr = mlx_xpm_file_to_image(cub->mlx, cub->ea,
			&cub->tex_size.ea_width, &cub->tex_size.ea_height);
	cub->so_ptr = mlx_xpm_file_to_image(cub->mlx, cub->so,
			&cub->tex_size.so_width, &cub->tex_size.so_height);
	cub->we_ptr = mlx_xpm_file_to_image(cub->mlx, cub->we,
			&cub->tex_size.we_width, &cub->tex_size.we_height);
	cub->speed = 12;
}
