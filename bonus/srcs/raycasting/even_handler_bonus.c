/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:02:04 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 16:51:49 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	view(t_cub *cub)
{
	if (cub->view == 2)
	{
		cub->view = 4;
		cub->dis_proj_plan = (WIDTH / cub->view) / tan(deg_to_rad(30));
	}
	else
	{
		cub->view = 2;
		cub->dis_proj_plan = (WIDTH / cub->view) / tan(deg_to_rad(30));
	}
	mlx_clear_window(cub->mlx, cub->mlx_win);
}

void	create_animation_thread(t_cub *cub, int *contr)
{
	t_list	*new;

	if (*contr == 0)
	{
		cub->th = malloc(sizeof(pthread_t));
		new = ft_lstnew(cub->th);
		ft_lstadd_back(&cub->ths, new);
		pthread_create(cub->th, NULL, animation_inc, (void *)cub);
	}
}

void	init_event(t_cub *cub, int key, int *contr)
{
	pthread_mutex_lock(&cub->mut2);
	*contr = cub->flag_terminated;
	pthread_mutex_unlock(&cub->mut2);
	cub->key = key;
}



int	event_handler(int key, t_cub *cub)
{
	int	contr;

	init_event(cub, key, &contr);
	if (key == 53)
	{
		kill_thread(cub);
		exit(0);
	}
	else if (key == 13 || key == 0 || key == 1 || key == 2 || key == 126
		|| key == 125)
		movement(cub, key);
	else if (key == 123 || key == 124)
		view_of_player(cub, key);
	else if (key == 69 || key == 78)
		controlle_speed(cub, key);
	else if (key == 49 && contr == 0)
		create_animation_thread(cub, &contr);
	else if (key == 31)
		open_dor(cub);
	else if (key == 48)
		view(cub);
	else
		return (0);
	re_render_images(cub);
	return (0);
}
