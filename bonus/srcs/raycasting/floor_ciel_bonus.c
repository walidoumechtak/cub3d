/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ciel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:24:28 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/11 15:49:07 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	floor_ceil(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				my_mlx_pixel_put(&cub->data, j, i, cub->ceiling_color);
			else
				my_mlx_pixel_put(&cub->data, j, i, cub->floor_color);
			j++;
		}
		i++;
	}
}
