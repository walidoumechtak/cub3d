/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:10:19 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/24 11:26:39 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	kill_thread(t_cub *cub)
{
	while (cub->ths != NULL)
	{
		pthread_join(*(pthread_t *)(cub->ths->content), NULL);
		cub->ths = cub->ths->next;
	}
}
