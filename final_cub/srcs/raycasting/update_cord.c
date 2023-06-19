/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:34:04 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/07 11:34:22 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	update_cord_endline(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->ply.xp;
	y = cub->ply.yp;
	if (cub->map[y][x] == 'N')
	{
		cub->ply.end_xline = cub->ply.pixel_x;
		cub->ply.end_yline = cub->ply.pixel_y - CARRE;
		// cub->ply.end_xline = cub->ply.pixel_x + CARRE;
		// cub->ply.end_yline = cub->ply.pixel_y;
	}
}
