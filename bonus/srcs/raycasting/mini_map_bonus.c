/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:16:02 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/22 21:44:46 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	player_in_mini_map(t_cub *cub)
{
	int	i;
	int	j;

	i = MINI_SIZE;
	while (i < MINI_SIZE + 5)
	{
		j = MINI_SIZE;
		while (j < MINI_SIZE + 5)
		{
			my_mlx_pixel_put(&cub->data, j * 0.7, i * 0.7, GOLD);
			j++;
		}
		i++;
	}
	draw_line(cub, cub->ply.end_xline * 0.7, cub->ply.end_yline * 0.7, GOLD);
}

// void	cases_of_mini(t_cub *cub)
// {
	
// }

void	mini_map(t_cub *cub)
{
	int	i;
	int	j;
	int	k;
	int	l;

	k = 0;
	i = cub->ply.pixel_y - MINI_SIZE;
	while (i < cub->ply.pixel_y + MINI_SIZE)
	{
		j = cub->ply.pixel_x - MINI_SIZE;
		l = 0;
		while (j < cub->ply.pixel_x + MINI_SIZE)
		{
			if (i < 0 || j < 0)
				my_mlx_pixel_put(&cub->data, l * 0.7, k * 0.7, BLACK);
			else if (i / CARRE >= y_size(cub) || j / CARRE >= x_size(cub)
					|| cub->map[i / CARRE][j / CARRE] == '\0' || cub->map[i
					/ CARRE][j / CARRE] == ' ')
				my_mlx_pixel_put(&cub->data, l * 0.7, k * 0.7, BLACK);
			else if (cub->map[i / CARRE][j / CARRE] == '1')
				my_mlx_pixel_put(&cub->data, l * 0.7, k * 0.7, RED);
			else if (cub->map[i / CARRE][j / CARRE] == '0' || cub->map[i
					/ CARRE][j / CARRE] == 'N' || cub->map[i / CARRE][j
					/ CARRE] == 'S' || cub->map[i / CARRE][j / CARRE] == 'W'
					|| cub->map[i / CARRE][j / CARRE] == 'E')
				my_mlx_pixel_put(&cub->data, l * 0.7, k * 0.7, 0xFFFFFF);
			else if (cub->map[i / CARRE][j / CARRE] == '2')
				my_mlx_pixel_put(&cub->data, l * 0.7, k * 0.7, GOLD);
			j++;
			l++;
		}
		k++;
		i++;
	}
	player_in_mini_map(cub);
}
