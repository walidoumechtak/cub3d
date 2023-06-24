/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_inc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:17:19 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	*animation_inc(void *arg)
{
	t_cub	*cub;
	int		i;

	cub = (t_cub *)arg;
	i = 0;
	pthread_mutex_lock(&cub->mut2);
	cub->flag_terminated = 1;
	pthread_mutex_unlock(&cub->mut2);
	while (i < 12)
	{
		usleep(70000);
		pthread_mutex_lock(&cub->mut);
		cub->guns_inc++;
		pthread_mutex_unlock(&cub->mut);
		i++;
	}
	pthread_mutex_lock(&cub->mut);
	cub->guns_inc = 1;
	pthread_mutex_unlock(&cub->mut);
	pthread_mutex_lock(&cub->mut2);
	cub->flag_terminated = 0;
	pthread_mutex_unlock(&cub->mut2);
	return (NULL);
}
