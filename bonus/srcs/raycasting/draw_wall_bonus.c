/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:04:16 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 12:55:03 by woumecht         ###   ########.fr       */
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

void	draw_wal(t_cub *cub, char flag, int x, int WALL_TEXTR)
{
	t_tex_data	tex_data;

	tex_data.col = 0;
	if (flag == 'H')
		hor_case(cub, WALL_TEXTR, x, tex_data);
	else
		ver_case(cub, WALL_TEXTR, x, tex_data);
}
