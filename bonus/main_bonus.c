/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:44:40 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/23 16:57:18 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	exit_mouse(int key, t_cub *cub)
{
	(void)key;
	kill_thread(cub);
	exit(0);
}

/**
 * @brief check if the argument is valid or not
 * @ac number of arguments
 * @av arguments
*/
int	ft_check_arg(int ac, char **av)
{
	char	*tmp;

	if (ac != 2)
		return (EXIT_FAILURE);
	tmp = ft_strchr(av[1], '.');
	if (!tmp)
		return (EXIT_FAILURE);
	if (ft_strncmp(tmp, ".cub", 4) || tmp[4])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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

int	anim(t_cub *cub)
{
	int	inc;

	inc = 0;
	pthread_mutex_lock(&cub->mut);
	inc = cub->guns_inc;
	pthread_mutex_unlock(&cub->mut);
	if (inc < 12 && inc != 1)
	{
		re_render_images(cub);
		pthread_mutex_lock(&cub->mut);
		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->guns_arr[inc],
				WIDTH / 2 - 250, HEIGHT - 281);
		inc = cub->guns_inc;
		pthread_mutex_unlock(&cub->mut);
	}
	return (0);
}

int	change_view_mouse(int button, int x, int y, t_cub *cub)
{
	(void)y;
	(void)x;
	if (button == 1 || button == 5)
	{
		cub->ply.dir = cub->ply.dir - deg_to_rad(R_VIEW);
		if (cub->ply.dir <= 0)
			cub->ply.dir = 2 * M_PI;
	}
	else if (button == 2 || button == 4)
	{
		cub->ply.dir = cub->ply.dir + deg_to_rad(R_VIEW);
		if (cub->ply.dir > 2 * M_PI)
			cub->ply.dir = 0;
	}
	else if (button == 3)
		open_dor(cub);
	cub->ply.end_xline = MINI_SIZE + 3 + (cos(cub->ply.dir) * (25));
	cub->ply.end_yline = MINI_SIZE + 3 + (sin(cub->ply.dir) * (25));
	re_render_images(cub);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	pthread_mutex_init(&cub->mut, NULL);
	pthread_mutex_init(&cub->mut2, NULL);
	if (ft_check_arg(ac, av))
		return (ft_putstr_fd("Error\nWrong arguments\n", 2), EXIT_FAILURE);
	if (ft_check_map(cub, av[1]))
		return (ft_putstr_fd("Error\nWrong map\n", 2), EXIT_FAILURE);
	cub->mlx = mlx_init();
	init_str(cub);
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "Cub3D");
	cub->data.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
			&cub->data.line_length, &cub->data.endian);
	re_render_images(cub);
	mlx_loop_hook(cub->mlx, &anim, cub);
	mlx_hook(cub->mlx_win, 2, 0, event_handler, cub);
	mlx_hook(cub->mlx_win, 17, 0, exit_mouse, cub);
	mlx_hook(cub->mlx_win, 4, 0, change_view_mouse, cub);
	mlx_loop(cub->mlx);
}
