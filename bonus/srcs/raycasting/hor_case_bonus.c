/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:45:52 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 11:46:19 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void    hor_case(t_cub *cub, int WALL_TEXTR, int x, t_tex_data tex_data)
{
    double  rest;
    
    rest = (cub->ph_inter_x / CARRE) - (int)(cub->ph_inter_x / CARRE);
    cub->dis_h = fabs(cos(fabs(cub->ray_dir - cub->ply.dir))
            * (cub->dis_h));
    tex_data.wall_height = ((CARRE / cub->dis_h) * cub->dis_proj_plan);
    tex_data.start_wall = ((HEIGHT / 2) - (tex_data.wall_height / 2));
    if (WALL_TEXTR == 'T')
    {
        if (cub->map[(int)cub->ph_inter_y / CARRE][(int)cub->ph_inter_x
            / CARRE] == '2')
        {
            tex_data.tx_ptr = cub->door;
            cub->x_offset = rest * cub->door_width;
            draw_textures(cub, x, cub->door_height, tex_data);
        }
        else
        {
            tex_data.tx_ptr = cub->no_ptr;
		    cub->x_offset = rest * cub->tex_size.no_width;
		    draw_textures(cub, x, cub->tex_size.no_height, tex_data);
        }
    }
    else
    {
        if (cub->map[(int)cub->ph_inter_y / CARRE][(int)cub->ph_inter_x
            / CARRE] == '2')
        {
            tex_data.tx_ptr = cub->door;
            cub->x_offset = rest * cub->door_width;
            draw_textures(cub, x, cub->door_height, tex_data);
        }
        else
        {
            tex_data.tx_ptr = cub->so_ptr;
		    cub->x_offset = rest * cub->tex_size.so_width;
		    draw_textures(cub, x, cub->tex_size.so_height, tex_data);
        }
    }
}