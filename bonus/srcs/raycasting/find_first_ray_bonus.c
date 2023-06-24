/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_ray_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:06:21 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	find_first_ray(t_cub *cub)
{
	int	i;

	i = 0;
	cub->ray_dir = (cub->ply.dir);
	while (i < (WIDTH / 2))
	{
		cub->ray_dir -= (M_PI / 3) / WIDTH;
		if ((cub->ray_dir) <= 0)
			cub->ray_dir = 2 * M_PI;
		i++;
	}
}
