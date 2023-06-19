/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:02:04 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/19 13:36:51 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	event_handler(int key, t_cub *cub)
{
	if (key == 53)
		exit(0);
	else if (key == 13 || key == 0 || key == 1 || key == 2 || key == 126
			|| key == 125)
	{
		mlx_clear_window(cub->mlx, cub->mlx_win);
		movement(cub, key);
	}
	else if (key == 123 || key == 124)
	{
		mlx_clear_window(cub->mlx, cub->mlx_win);
		view_of_player(cub, key);
	}
	else
		return (0);
	floor_ceil(cub);
	rays(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->data.img, 0, 0);
	return (0);
}
