/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:51:24 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/24 11:26:49 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	re_render_images(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlx_win);
	floor_ceil(cub);
	rays(cub);
	mini_map(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->data.img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->guns_arr[0], WIDTH / 2
		- 250, HEIGHT - 281);
	build_msg(cub);
}
