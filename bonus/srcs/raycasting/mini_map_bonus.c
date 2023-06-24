/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:16:02 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

typedef struct s_mini_map
{
	int	i;
	int	j;
	int	k;
	int	l;
}		t_mini_map;

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

void	cases_of_mini(t_cub *cub, t_mini_map mini)
{
	if (mini.i < 0 || mini.j < 0)
		my_mlx_pixel_put(&cub->data, mini.l * 0.7, mini.k * 0.7, BLACK);
	else if (mini.i / CARRE >= y_size(cub) || mini.j / CARRE >= x_size(cub)
		|| cub->map[mini.i / CARRE][mini.j / CARRE] == '\0'
			|| cub->map[mini.i / CARRE][mini.j / CARRE] == ' ')
		my_mlx_pixel_put(&cub->data, mini.l * 0.7, mini.k * 0.7, BLACK);
	else if (cub->map[mini.i / CARRE][mini.j / CARRE] == '1')
		my_mlx_pixel_put(&cub->data, mini.l * 0.7, mini.k * 0.7, RED);
	else if (cub->map[mini.i / CARRE][mini.j / CARRE] == '0' || cub->map[mini.i
			/ CARRE][mini.j / CARRE] == 'N' || cub->map[mini.i / CARRE][mini.j
			/ CARRE] == 'S' || cub->map[mini.i / CARRE][mini.j / CARRE] == 'W'
			|| cub->map[mini.i / CARRE][mini.j / CARRE] == 'E')
		my_mlx_pixel_put(&cub->data, mini.l * 0.7, mini.k * 0.7, 0xFFFFFF);
	else if (cub->map[mini.i / CARRE][mini.j / CARRE] == '2')
		my_mlx_pixel_put(&cub->data, mini.l * 0.7, mini.k * 0.7, GOLD);
}

void	mini_map(t_cub *cub)
{
	t_mini_map	mini;

	mini.k = 0;
	mini.i = cub->ply.pixel_y - MINI_SIZE;
	while (mini.i < cub->ply.pixel_y + MINI_SIZE)
	{
		mini.j = cub->ply.pixel_x - MINI_SIZE;
		mini.l = 0;
		while (mini.j < cub->ply.pixel_x + MINI_SIZE)
		{
			cases_of_mini(cub, mini);
			mini.j++;
			mini.l++;
		}
		mini.k++;
		mini.i++;
	}
	player_in_mini_map(cub);
}
