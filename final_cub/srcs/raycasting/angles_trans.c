/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:38:16 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/18 15:39:26 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

double	deg_to_rad(double deg)
{
	return (((deg * M_PI) / 180));
}

double	rad_to_deg(double rad)
{
	return ((rad * 180 / M_PI));
}
