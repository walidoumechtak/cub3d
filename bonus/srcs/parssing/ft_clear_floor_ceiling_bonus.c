/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_floor_ceiling_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:48:49 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/25 11:15:38 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

void	ft_clear_floor_ceiling(t_cub *cub)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (cub->f[i] && cub->c[i] && i < 3)
	{
		j = -1;
		tmp = cub->f[i];
		cub->f[i] = ft_strtrim(cub->f[i], " ");
		while (cub->f[i][++j])
		{
			if (!ft_isdigit(cub->f[i][j]) && cub->f[i][j] != ',')
				(ft_putstr_fd("Error\nInvalid floor color\n", 2), exit(1));
		}
		free(tmp);
		tmp = cub->c[i];
		cub->c[i] = ft_strtrim(cub->c[i], " ");
		j = -1;
		while (cub->c[i][++j])
			if (!ft_isdigit(cub->c[i][j]) && cub->c[i][j] != ',')
				(ft_putstr_fd("Error\nInvalid ceiling color\n", 2), exit(1));
		free(tmp);
		i++;
	}
}
