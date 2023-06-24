/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_floor_ceiling_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:48:49 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/24 13:16:07 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	ft_clear_floor_ceiling(t_cub *cub)
{
	char	*tmp;
	int		index;

	index = 0;
	while (cub->f[index] && cub->c[index] && index < 3)
	{
		tmp = cub->f[index];
		cub->f[index] = ft_strtrim(cub->f[index], " ");
		free(tmp);
		tmp = cub->c[index];
		cub->c[index] = ft_strtrim(cub->c[index], " ");
		free(tmp);
		index++;
	}
}
