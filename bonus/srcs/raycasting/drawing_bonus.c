/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:34:45 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/07 11:37:11 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	drawing(t_cub *cub, int sx, int sy, int x, int y, int color)
{
	double	xd;
	double	yd;
	int		dx;
	int		dy;
	int		steps;
	double	xIncrement;
	double	yIncrement;

	dx = x - sx;
	dy = y - sy;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
	xIncrement = (double)dx / steps;
	yIncrement = (double)dy / steps;
	xd = sx;
	yd = sy;
	while (steps > 0)
	{
		my_mlx_pixel_put(&cub->data, (int)((xd)), (int)((yd)), color);
		xd += xIncrement;
		yd += yIncrement;
		steps--;
	}
}
