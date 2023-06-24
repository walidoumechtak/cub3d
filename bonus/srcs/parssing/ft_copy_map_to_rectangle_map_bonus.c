/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map_to_rectangle_map_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:02:34 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

static int	get_max_width(char **map)
{
	int	i;
	int	width;
	int	len;

	i = 0;
	width = -1;
	while (map && map[i])
	{
		len = ft_strlen(map[i]);
		if (width < len)
			width = len;
		i++;
	}
	return (width);
}

static int	get_len(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

char	**ft_copy_map_to_rectangle_map(char **map)
{
	char	**map_cpy;
	int		width;
	int		i;
	int		j;

	map_cpy = malloc(sizeof(char *) * (get_len(map) + 1));
	if (!map_cpy)
		return (NULL);
	width = get_max_width(map);
	i = -1;
	while (map && map[++i])
	{
		j = -1;
		map_cpy[i] = malloc(sizeof(char) * (width + 1));
		if (!map_cpy[i])
			return (NULL);
		while (map[i][++j])
			map_cpy[i][j] = map[i][j];
		while (j < width)
			map_cpy[i][j++] = ' ';
		map_cpy[i][j] = '\0';
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}
