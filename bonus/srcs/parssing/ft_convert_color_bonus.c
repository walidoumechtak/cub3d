/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_color_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:07:59 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/25 11:16:14 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

int	ft_convert_color(char **str)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	red = ft_atoi(str[0]);
	green = ft_atoi(str[1]);
	blue = ft_atoi(str[2]);
	if (red < 0 || red > 255 || green < 0 || green > 255
		|| blue < 0 || blue > 255)
		(ft_putstr_fd("Error\nColor is not valid\n", 2), exit(1));
	color = red << 16 | green << 8 | blue;
	return (color);
}
