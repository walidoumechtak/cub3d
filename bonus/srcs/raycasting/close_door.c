/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:59:09 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 11:10:42 by woumecht         ###   ########.fr       */
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
