/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlle_speed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:19:33 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/25 08:46:31 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	controlle_speed(t_cub *cub, int key)
{
	if (key == 69)
	{
		if (cub->speed == 17)
			printf("You are in the heigher speed !!!");
		else
			cub->speed++;
	}
	else
	{
		if (cub->speed == 7)
			printf("You are in the lower speed !!!\n");
		else
			cub->speed--;
	}
}
