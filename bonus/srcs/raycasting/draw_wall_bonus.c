/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:04:16 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 11:48:13 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	get_pixel(t_cub *cub, int i, int j, void *ptr)
{
	int		line_len;
	int		bpp;
	int		endian;
	char	*add;
	int		*color;

	(void)cub;
	add = mlx_get_data_addr(ptr, &bpp, &line_len, &endian);
	color = NULL;
	color = (int *)(add + (i * line_len) + (j * (bpp / 8)));
	return (*color);
}

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

void	draw_wal(t_cub *cub, char flag, int x, int WALL_TEXTR)
{
	t_tex_data	tex_data;

	tex_data.col = 0;
	if (flag == 'H')
		hor_case(cub, WALL_TEXTR, x, tex_data);
	else
		ver_case(cub, WALL_TEXTR, x, tex_data);
}
