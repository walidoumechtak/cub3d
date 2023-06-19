/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_ver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:10:03 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/16 11:45:46 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int    ray_cast_ver(t_cub *cub)
{
    int x;

    x = 0;
    // printf("ver x %f, ver y : %f\n", cub->pv_inter_x, cub->pv_inter_y);
    // printf("y_size : %d, x_size : %d\n", y_size(cub) , x_size(cub) );
    if (cub->pv_inter_y <= 0)
        (cub->pv_inter_y = CARRE, x = 1);
    else if (cub->pv_inter_y >= (y_size(cub)) * CARRE)
        (cub->pv_inter_y = (y_size(cub)) * CARRE - CARRE, x = 1);
    if (cub->pv_inter_x >= (x_size(cub) * CARRE - CARRE))
    {
        cub->pv_inter_x = x_size(cub) * CARRE - CARRE;
        return (1);
    }
    if (x == 1)
        return (1);
    if (cub->map[(int)(cub->pv_inter_y / CARRE)][(int)(cub->pv_inter_x / CARRE)] == '1')
        return (1);
    else
    {
        cub->pv_inter_x += (cub->dv_x_ray);
        cub->pv_inter_y += (cub->dv_y_ray);
    }
    return (0);
}
