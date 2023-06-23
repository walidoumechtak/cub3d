/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlle_speed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:19:33 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/23 10:19:59 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	controlle_speed(t_cub *cub, int key)
{
	if (key == 69)
	{
		if (cub->speed == 25)
			printf("You are in the heigher speed !!!");
		else
			cub->speed++;
	}
	else
	{
		if (cub->speed == 5)
			printf("You are in the lower speed !!!\n");
		else
			cub->speed--;
	}
}
