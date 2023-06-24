/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:37:26 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	draw_line(t_cub *cub, int x, int y, int color)
{
	double	dx;
	double	dy;
	int		steps;
	double	x_inc;
	double	y_inc;

	dx = x - (int)((MINI_SIZE + 3) * 0.7);
	dy = y - (int)((MINI_SIZE + 3) * 0.7);
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	dx = (int)((MINI_SIZE + 3) * 0.7);
	dy = (int)((MINI_SIZE + 3) * 0.7);
	while (steps >= 0)
	{
		my_mlx_pixel_put(&cub->data, (int)((dx)), (int)((dy)), color);
		dx += x_inc;
		dy += y_inc;
		steps--;
	}
}
