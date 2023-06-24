/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:54:42 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/23 20:30:21 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

char	**ft_clean_map(char **map)
{
	int		i;
	char	**clean_map;

	i = 0;
	while (map[i])
		i++;
	clean_map = malloc(sizeof(char *) * (i - 5));
	i = 6;
	while (map[i])
	{
		clean_map[i - 6] = ft_strdup(map[i]);
		i++;
	}
	clean_map[i - 6] = NULL;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	return (clean_map);
}
