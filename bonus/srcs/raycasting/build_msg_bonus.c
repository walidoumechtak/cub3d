/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:49:22 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 17:50:50 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	build_msg(t_cub *cub)
{
	char	*speed;

	speed = ft_itoa(cub->speed);
	cub->msg = ft_strjoin("Speed: ", speed);
	free(speed);
	if (cub->speed > 22)
		mlx_string_put(cub->mlx, cub->mlx_win, WIDTH - 140, 20, ORANGE,
			cub->msg);
	else
		mlx_string_put(cub->mlx, cub->mlx_win, WIDTH - 140, 20, 0xFFFFFF,
			cub->msg);
	free(cub->msg);
}
