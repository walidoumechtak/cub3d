/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:44:40 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/19 13:34:24 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	exit_mouse(int key)
{
	(void)key;
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

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
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
	floor_ceil(cub);
	rays(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->data.img, 0, 0);
	mlx_hook(cub->mlx_win, 2, 0, event_handler, cub);
	mlx_hook(cub->mlx_win, 17, 0, exit_mouse, cub);
	mlx_loop(cub->mlx);
}
