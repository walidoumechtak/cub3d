/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:15:07 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/22 21:50:32 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	re_draw(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlx_win);
	floor_ceil(cub);
	rays(cub);
	mini_map(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->data.img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->guns_arr[0], WIDTH / 2
			- 250, HEIGHT - 281);
	build_msg(cub);
}

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
			if (cub->map[i][j] == '3' && cub->map[(int)cub->ply.pixel_y
				/ CARRE][(int)cub->ply.pixel_x / CARRE] != '3'
				&& cub->map[(int)(cub->ply.pixel_y + (sin(cub->ply.dir)
						* CARRE)) / CARRE][(int)(cub->ply.pixel_x
					+ (cos(cub->ply.dir) * CARRE)) / CARRE] != '3')
				cub->map[i][j] = '2';
			j++;
		}
		i++;
	}
	re_draw(cub);
}

int	check_other_side(t_cub *cub, double x, double y)
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
		{
			return (1);
		}
		eng += incr;
	}
	return (0);
}

void	move_player_loop(t_cub *cub, int x, int y, int rot)
{
	int	i;

	i = 0;
	while (i < cub->speed)
	{
		x += ((cos(cub->ply.dir + rot)) * cub->ply.dir_vec);
		y += ((sin(cub->ply.dir + rot)) * cub->ply.dir_vec);
		if (cub->map[((int)y) / CARRE][((int)x) / CARRE] == '1'
			|| cub->map[((int)y) / CARRE][((int)x) / CARRE] == ' '
			|| cub->map[((int)y) / CARRE][((int)x) / CARRE] == '2')
		{
			if (cub->friction == 1)
				cub->ply.pixel_x += cos(cub->ply.dir);
			else if (cub->friction == 2)
				cub->ply.pixel_y += sin(cub->ply.dir);
			return ;
		}
		i++;
	}
}

void	move_player(t_cub *cub, double rot)
{
	double	x;
	double	y;
	
	y = (cub->ply.pixel_y + (sin(cub->ply.dir + rot)));
	x = (cub->ply.pixel_x + (cos(cub->ply.dir + rot)));
	move_player_loop(cub, x, y, rot);
	if (check_other_side(cub, x, y) == 1)
	{
		if (cub->friction == 1)
			cub->ply.pixel_x += cos(cub->ply.dir);
		else if (cub->friction == 2)
			cub->ply.pixel_y += sin(cub->ply.dir);
		return ;
	}
	close_door(cub);
	cub->ply.pixel_x = x;
	cub->ply.pixel_y = y;
	cub->ply.end_xline = MINI_SIZE + 3 + (cos(cub->ply.dir) * (25));
	cub->ply.end_yline = MINI_SIZE + 3 + (sin(cub->ply.dir) * (25));
}
