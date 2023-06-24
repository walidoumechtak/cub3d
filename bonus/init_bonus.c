/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:22:31 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/24 13:02:37 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	get_player_cord(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E'
				|| cub->map[i][j] == 'S' || cub->map[i][j] == 'W')
			{
				cub->ply.xp = j;
				cub->ply.yp = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	fill_guns_array(t_cub *cub)
{
	int		i;
	int		j;
	char	*file_name;
	char	*c;
	char	*temp;

	i = 4;
	j = 0;
	while (j < 12)
	{
		c = ft_itoa(i++);
		temp = ft_strjoin(c, ".xpm");
		free(c);
		file_name = ft_strjoin("textures/gun/", temp);
		free(temp);
		cub->guns_arr[j] = mlx_xpm_file_to_image(cub->mlx, file_name,
				&cub->size_gun, &cub->size_gun);
		free(file_name);
		if (cub->guns_arr[j] == NULL)
		{
			ft_putendl_fd("Something wrong with your textures !!!", 2);
			exit(1);
		}
		j++;
	}
}

void	init_textures(t_cub *cub)
{
	cub->no_ptr = mlx_xpm_file_to_image(cub->mlx, cub->no,
			&cub->tex_size.no_width, &cub->tex_size.no_height);
	cub->ea_ptr = mlx_xpm_file_to_image(cub->mlx, cub->ea,
			&cub->tex_size.ea_width, &cub->tex_size.ea_height);
	cub->so_ptr = mlx_xpm_file_to_image(cub->mlx, cub->so,
			&cub->tex_size.so_width, &cub->tex_size.so_height);
	cub->we_ptr = mlx_xpm_file_to_image(cub->mlx, cub->we,
			&cub->tex_size.we_width, &cub->tex_size.we_height);
	cub->door = mlx_xpm_file_to_image(cub->mlx, "textures/door.xpm",
			&cub->door_width, &cub->door_height);
	if (!cub->no_ptr || !cub->ea_ptr || !cub->so_ptr || !cub->we_ptr
		|| !cub->door)
	{
		ft_putendl_fd("Something wrong with your textures !!!", 2);
		exit(1);
	}
}

void	starting_player(t_cub *cub)
{
	if (cub->map[cub->ply.yp][cub->ply.xp] == 'N')
		cub->ply.dir = deg_to_rad(270);
	else if (cub->map[cub->ply.yp][cub->ply.xp] == 'S')
		cub->ply.dir = deg_to_rad(90);
	else if (cub->map[cub->ply.yp][cub->ply.xp] == 'W')
		cub->ply.dir = deg_to_rad(180);
	else if (cub->map[cub->ply.yp][cub->ply.xp] == 'E')
		cub->ply.dir = deg_to_rad(0);
}

void	init_str(t_cub *cub)
{
	get_player_cord(cub);
	cub->ply.move_speed = 3;
	cub->ply.dir_vec = 0;
	cub->is_wall = 0;
	starting_player(cub);
	cub->ply.pixel_x = cub->ply.xp * CARRE + 10;
	cub->ply.pixel_y = cub->ply.yp * CARRE + 10;
	cub->ray_dir = (cub->ply.dir - (deg_to_rad(30)));
	cub->view = 2;
	cub->dis_proj_plan = (WIDTH / cub->view) / tan(deg_to_rad(30));
	cub->dis_h = 0;
	cub->dis_v = 0;
	cub->ply.end_xline = MINI_SIZE + 3 + (cos(cub->ply.dir) * (25));
	cub->ply.end_yline = MINI_SIZE + 3 + (sin(cub->ply.dir) * (25));
	cub->speed = 10;
	init_textures(cub);
	fill_guns_array(cub);
	cub->guns_inc = 1;
	cub->flag_terminated = 0;
	cub->x_midle_ray = -1;
	cub->y_midle_ray = -1;
	cub->th = NULL;
	cub->friction = 0;
	cub->ths = NULL;
}
