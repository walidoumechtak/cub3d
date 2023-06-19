/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:00:28 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/10 11:09:14 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	ft_check_pos(char **map, int i, int j, int flag)
{
	while (map[i] && map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (1);
		else if (map[i][j] == '1')
			break ;
		if (flag)
			i++;
		else
			j++;
	}
	return (0);
}

static int	ft_check_neg(char **map, int i, int j, int flag)
{
	while (j >= 0 && i >= 0 && map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (1);
		else if (map[i][j] == '1')
			break ;
		if (flag)
			i--;
		else
			j--;
	}
	return (0);
}

static int	ft_check_wall_between_spaces(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ' || i == 0 || j == 0
				|| !map[i + 1] || !map[i][j + 1])
			{
				if (ft_check_pos(map, i, j, 0) || ft_check_neg(map, i, j, 0)
					|| ft_check_pos(map, i, j, 1) || ft_check_neg(map, i, j, 1))
					return (1);
			}
		}
	}
	return (0);
}

/**
 * @brief check if the map is surrounded by walls
 * @param map variable containing the map in the form of a table
 * @return 1 if the map is surrounded by walls, 0 otherwise
*/

int	ft_check_map_wall(t_cub *cub)
{
	char	**tmp;
	int		i;

	i = 0;
	while (cub->map && cub->map[i])
		i++;
	if (i < 5)
		return (0);
	tmp = ft_copy_map_to_rectangle_map(cub->map + 6);
	if (!tmp)
		return (ft_putstr_fd("Error\nMalloc failed\n", 2), exit(1), 0);
	if (ft_check_wall_between_spaces(tmp))
		return (free_map(tmp), 0);
	free_map(cub->map);
	cub->map = tmp;
	return (1);
}
