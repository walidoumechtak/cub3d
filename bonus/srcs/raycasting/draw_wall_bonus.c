/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:04:16 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	draw_wal(t_cub *cub, char flag, int x, int WALL_TEXTR)
{
	t_tex_data	tex_data;

	tex_data.col = 0;
	if (flag == 'H')
		hor_case(cub, WALL_TEXTR, x, tex_data);
	else
		ver_case(cub, WALL_TEXTR, x, tex_data);
}
