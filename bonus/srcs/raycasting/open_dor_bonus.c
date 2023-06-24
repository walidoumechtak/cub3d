/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:45:14 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	open_dor(t_cub *cub)
{
	int	dis;

	if (cub->x_midle_ray != -1 && cub->x_midle_ray != -1)
	{
		dis = (int)calcdistance(cub, cub->x_midle_ray, cub->y_midle_ray);
		if (dis <= 20 && dis >= 3)
		{
			cub->map[(int)cub->y_midle_ray / CARRE][(int)cub->x_midle_ray
				/ CARRE] = '3';
		}
	}
}
