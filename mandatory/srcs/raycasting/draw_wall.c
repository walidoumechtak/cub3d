/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:04:16 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/21 17:05:17 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

typedef struct s_textures_data
{
	int		wall_height;
	double	start_wall;
	int		col;
	void	*tx_ptr;
	int		text_height;
}			t_tex_data;

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

void	hor_case(t_cub *cub, int WALL_TEXTR, int x, t_tex_data tex_data)
{
	double	rest;

	rest = (cub->ph_inter_x / CARRE) - (int)(cub->ph_inter_x / CARRE);
	cub->dis_h = fabs(cos(fabs(cub->ray_dir - cub->ply.dir)) * (cub->dis_h));
	tex_data.wall_height = ((CARRE / cub->dis_h) * cub->dis_proj_plan);
	tex_data.start_wall = ((HEIGHT / 2) - (tex_data.wall_height / 2));
	if (WALL_TEXTR == 'T')
	{
		tex_data.tx_ptr = cub->no_ptr;
		cub->x_offset = rest * cub->tex_size.no_width;
		draw_textures(cub, x, cub->tex_size.no_height, tex_data);
	}
	else
	{
		tex_data.tx_ptr = cub->so_ptr;
		cub->x_offset = rest * cub->tex_size.so_width;
		draw_textures(cub, x, cub->tex_size.so_height, tex_data);
	}
}

void	ver_case(t_cub *cub, int WALL_TEXTR, int x, t_tex_data tex_data)
{
	double	rest;

	rest = (cub->pv_inter_y / CARRE) - (int)(cub->pv_inter_y / CARRE);
	cub->dis_v = fabs(cos(fabs(cub->ray_dir - cub->ply.dir)) * (cub->dis_v));
	tex_data.wall_height = ((CARRE / cub->dis_v) * cub->dis_proj_plan);
	tex_data.start_wall = ((HEIGHT / 2) - (tex_data.wall_height / 2));
	if (WALL_TEXTR == 'R')
	{
		tex_data.tx_ptr = cub->we_ptr;
		cub->x_offset = rest * cub->tex_size.we_width;
		draw_textures(cub, x, cub->tex_size.we_height, tex_data);
	}
	else if (WALL_TEXTR == 'L')
	{
		tex_data.tx_ptr = cub->ea_ptr;
		cub->x_offset = rest * cub->tex_size.ea_width;
		draw_textures(cub, x, cub->tex_size.ea_height, tex_data);
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
