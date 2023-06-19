/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:15:07 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/19 15:49:16 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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
			|| cub->map[(int)(y + i) / CARRE][(int)(x + j) / CARRE] == ' ')
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
	y = (cub->ply.pixel_y + (sin(cub->ply.dir + rot)) * cub->ply.dir_vec);
	x = (cub->ply.pixel_x + (cos(cub->ply.dir + rot)) * cub->ply.dir_vec);
	while (i < cub->speed)
	{
		x += ((cos(cub->ply.dir + rot)) * cub->ply.dir_vec);
		y += ((sin(cub->ply.dir + rot)) * cub->ply.dir_vec);
		if (cub->map[((int)y) / CARRE][((int)x) / CARRE] == '1'
			|| cub->map[((int)y) / CARRE][((int)x) / CARRE] == ' ')
		{
			cub->is_wall = 1;
			return ;
		}
		i++;
	}
	if (check_other_side(cub, x, y) == 1)
		return ;
	cub->ply.pixel_x = x;
	cub->ply.pixel_y = y;
	cub->ply.end_xline = MINI_SIZE + 3 + (cos(cub->ply.dir) * (25));
	cub->ply.end_yline = MINI_SIZE + 3 + (sin(cub->ply.dir) * (25));
}
