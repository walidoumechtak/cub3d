/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:16:59 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/07 11:17:19 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_rectangle(t_cub *cub, int color, int sy, int sx)
{
	int	i_sy;
	int	j_sx;

	i_sy = sy;
	while (i_sy < sy + CARRE)
	{
		j_sx = sx;
		while (j_sx < sx + CARRE)
		{
			if ((j_sx == sx + 24 || i_sy == sy + 24))
				my_mlx_pixel_put(&cub->data, (int)j_sx, (int)i_sy, 0x000000);
			else
				my_mlx_pixel_put(&cub->data, (int)j_sx, (int)i_sy, color);
			j_sx++;
		}
		i_sy++;
	}
}
