/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:15:07 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/22 08:29:56 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	close_door(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '3' && cub->map[(int)cub->ply.pixel_y / CARRE][(int)cub->ply.pixel_x / CARRE] != '3'
				 && cub->map[(int)(cub->ply.pixel_y + (sin(cub->ply.dir) * CARRE)) / CARRE][(int)(cub->ply.pixel_x + (cos(cub->ply.dir) * CARRE)) / CARRE] != '3')
				cub->map[i][j] = '2';
			j++;
		}
		i++;
	}
	mlx_clear_window(cub->mlx, cub->mlx_win);
	floor_ceil(cub);
    rays(cub);
    mini_map(cub);
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->data.img, 0, 0);
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->guns_arr[0], WIDTH / 2 - 250, HEIGHT - 281);
    build_msg(cub);
}

int	check_other_side(t_cub *cub, int x, int y)
{
	double	eng;
	double	incr;
	double	i;
	double	j;

	eng = deg_to_rad(0);
	incr = (2 * M_PI) / 100;
	while (eng < deg_to_rad(360))
	{
		i = sin(eng) * 5;
		j = cos(eng) * 5;
		if (cub->map[(int)(y + i) / CARRE][(int)(x + j) / CARRE] == '1'
			|| cub->map[(int)(y + i) / CARRE][(int)(x + j) / CARRE] == ' '
			|| cub->map[(int)(y + i) / CARRE][(int)(x + j) / CARRE] == '2')
			return (1);
		eng += incr;
	}
	return (0);
}

void	move_player(t_cub *cub, double rot)
{
	double	x;
	double	y;
	int		i;

	i = 0;
	y = (cub->ply.pixel_y + (sin(cub->ply.dir + rot)));
	x = (cub->ply.pixel_x + (cos(cub->ply.dir + rot)));
	while (i < cub->speed)
	{
		x += ((cos(cub->ply.dir + rot)) * cub->ply.dir_vec);
		y += ((sin(cub->ply.dir + rot)) * cub->ply.dir_vec);
		if (cub->map[((int)y) / CARRE][((int)x) / CARRE] == '1'
			|| cub->map[((int)y) / CARRE][((int)x) / CARRE] == ' '
			|| cub->map[((int)y) / CARRE][((int)x) / CARRE] == '2')
		{
			// if ((cub->ply.dir >= deg_to_rad(240) && cub->ply.dir <= deg_to_rad(300))
			// 	|| (cub->ply.dir >= deg_to_rad(60) && cub->ply.dir <= deg_to_rad(120)))
			// 	cub->ply.pixel_x += cos(cub->ply.dir);
			// else if ((cub->ply.dir >= deg_to_rad(150) && cub->ply.dir <= deg_to_rad(210))
			// 	|| (cub->ply.dir >= deg_to_rad(330) && cub->ply.dir <= deg_to_rad(30)))
			// 	cub->ply.pixel_y += sin(cub->ply.dir);
			//cub->is_wall = 1;
			return ;
		}
		i++;
	}
	if (check_other_side(cub, x, y) == 1)
		return ;
	close_door(cub);
	cub->ply.pixel_x = x;
	cub->ply.pixel_y = y;
	cub->ply.end_xline = MINI_SIZE + 3 + (cos(cub->ply.dir) * (25));
	cub->ply.end_yline = MINI_SIZE + 3 + (sin(cub->ply.dir) * (25));
}
