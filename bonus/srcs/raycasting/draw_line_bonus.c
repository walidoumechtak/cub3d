/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:37:26 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/07 18:37:44 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_line(t_cub *cub, int x, int y, int color)
{
	double	xd;
	double	yd;
	int		i;
	int		dx;
	int		dy;
	int		steps;
	double	xIncrement;
	double	yIncrement;

	i = 0;
	dx = x - (int)cub->ply.pixel_x;
	dy = y - (int)cub->ply.pixel_y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xIncrement = (double)dx / steps;
	yIncrement = (double)dy / steps;
	xd = cub->ply.pixel_x;
	yd = cub->ply.pixel_y;
	while (i <= steps)
	{
		my_mlx_pixel_put(&cub->data, (int)((xd)), (int)((yd)), color);
		xd += xIncrement;
		yd += yIncrement;
		i++;
	}
}
