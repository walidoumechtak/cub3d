/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:54:42 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/21 11:39:52 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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
