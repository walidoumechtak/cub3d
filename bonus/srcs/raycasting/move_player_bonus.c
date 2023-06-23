/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:15:07 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 11:15:55 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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

void	move_player_loop(t_cub *cub, double *x, double *y, int rot)
{
	int	i;

	i = 0;
	while (i < cub->speed)
	{
		*x += ((cos(cub->ply.dir + rot)) * cub->ply.dir_vec);
		*y += ((sin(cub->ply.dir + rot)) * cub->ply.dir_vec);
		if (cub->map[((int)*y) / CARRE][((int)*x) / CARRE] == '1'
			|| cub->map[((int)*y) / CARRE][((int)*x) / CARRE] == ' '
			|| cub->map[((int)*y) / CARRE][((int)*x) / CARRE] == '2')
		{
			return ;
		}
		i++;
	}
}

void	move_player(t_cub *cub, double rot)
{
	double	x;
	double	y;

	y = (cub->ply.pixel_y + (sin(cub->ply.dir + rot)) * cub->ply.dir_vec);
	x = (cub->ply.pixel_x + (cos(cub->ply.dir + rot)) * cub->ply.dir_vec);
	move_player_loop(cub, &x, &y, rot);
	if (check_other_side(cub, x, y) == 1)
	{
		if (cub->friction == 1 && cub->map[(int)y / CARRE][(int)(x
			+ (cos(cub->ply.dir) * 1)) / CARRE] != '1' && (cub->key == 13
				|| cub->key == 126))
			cub->ply.pixel_x += cos(cub->ply.dir);
		else if (cub->friction == 2 && cub->map[(int)(y + (sin(cub->ply.dir)
					* 1)) / CARRE][(int)x / CARRE] != '1' && (cub->key == 13
					|| cub->key == 126))
			cub->ply.pixel_y += sin(cub->ply.dir);
		return ;
	}
	close_door(cub);
	cub->ply.pixel_x = x;
	cub->ply.pixel_y = y;
	cub->ply.end_xline = MINI_SIZE + 3 + (cos(cub->ply.dir) * (25));
	cub->ply.end_yline = MINI_SIZE + 3 + (sin(cub->ply.dir) * (25));
}
