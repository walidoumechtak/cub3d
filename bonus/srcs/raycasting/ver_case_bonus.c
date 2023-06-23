/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_case_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:47:35 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 11:48:20 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ver_case(t_cub *cub, int WALL_TEXTR, int x, t_tex_data tex_data)
{
    double  rest;
    
    rest = (cub->pv_inter_y / CARRE) - (int)(cub->pv_inter_y / CARRE);
    cub->dis_v = fabs(cos(fabs(cub->ray_dir - cub->ply.dir))
            * (cub->dis_v));
    tex_data.wall_height = ((CARRE / cub->dis_v) * cub->dis_proj_plan);
    tex_data.start_wall = ((HEIGHT / 2) - (tex_data.wall_height / 2));
    if (WALL_TEXTR == 'R')
    {
        if (cub->map[(int)cub->pv_inter_y / CARRE][(int)cub->pv_inter_x
            / CARRE] == '2')
        {
             tex_data.tx_ptr = cub->door;
            cub->x_offset = rest * cub->door_width;
            draw_textures(cub, x, cub->door_height, tex_data);
        }
        else
        {
            tex_data.tx_ptr = cub->we_ptr;
		    cub->x_offset = rest * cub->tex_size.we_width;
		    draw_textures(cub, x, cub->tex_size.we_height, tex_data);
        }
    }
    else if (WALL_TEXTR == 'L')
    {
        if (cub->map[(int)cub->pv_inter_y / CARRE][(int)cub->pv_inter_x
            / CARRE] == '2')
        {
            tex_data.tx_ptr = cub->door;
            cub->x_offset = rest * cub->door_width;
            draw_textures(cub, x, cub->door_height, tex_data);
        }
        else
        {
            tex_data.tx_ptr = cub->ea_ptr;
		    cub->x_offset = rest * cub->tex_size.ea_width;
		    draw_textures(cub, x, cub->tex_size.ea_height, tex_data);
        }
    }
}
