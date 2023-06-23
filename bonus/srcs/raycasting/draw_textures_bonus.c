/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:55:05 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 12:55:49 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_textures(t_cub *cub, int col, int tex_height, t_tex_data tex_data)
{
	int		color;
	double	i;
	double	s;
	double	j;

	i = 0;
	if (tex_data.wall_height >= HEIGHT)
	{
		s = (tex_data.wall_height / 2) - (HEIGHT / 2);
		i = ((s * 100 / (tex_data.wall_height)) / 100) * tex_height;
	}
	if (tex_data.start_wall < 0)
		tex_data.start_wall = 0;
	j = tex_data.start_wall;
	while (tex_data.start_wall < (int)(tex_data.wall_height) + j)
	{
		if (tex_data.start_wall >= HEIGHT)
			break ;
		color = get_pixel(cub, (int)i, cub->x_offset, tex_data.tx_ptr);
		my_mlx_pixel_put(&cub->data, col, tex_data.start_wall, color);
		tex_data.start_wall++;
		if (i < tex_height)
			i += (tex_height / (double)tex_data.wall_height);
	}
}
