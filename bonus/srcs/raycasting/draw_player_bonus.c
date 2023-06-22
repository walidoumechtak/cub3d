/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:17:40 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/07 11:18:02 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void    draw_player(t_cub *cub, int color)
{
    int i;
    int j;

    i = cub->ply.pixel_y;
    while (i < cub->ply.pixel_y + 5)
    {
        j = cub->ply.pixel_x;
        while (j < cub->ply.pixel_x + 5)
        {
                my_mlx_pixel_put(&cub->data, (int)j, (int)i, color);
            j++;
        }
        i++;
    }
}
