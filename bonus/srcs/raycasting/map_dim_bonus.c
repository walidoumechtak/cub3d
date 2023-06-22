/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:52:29 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/16 10:27:31 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int x_size(t_cub *cub)
{
    int i = 0;
    while (cub->map[0][i])
        i++;
    return (i);
}

int y_size(t_cub *cub)
{
    int i = 0;
    while (cub->map[i])
        i++;
    return (i);
}