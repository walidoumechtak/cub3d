/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:43:32 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/24 13:16:33 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d_bonus.h"

int	ft_check_map_char(char **map)
{
	int	i;
	int	j;
	int player;

	i = 5;
	player = 0;
	while (map && map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != ' ')
				return (0);
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				player++;
			if (player != 1 && player != 0)
				return (0);
		}
	}
	if (player != 1)
		return (0);
	return (1);
}

void	ft_set_data(t_cub *cub, int i, int j)
{
	if (cub->map[i][j] == 'N' && cub->map[i][j + 1] == 'O'
			&& cub->map[i][j + 2] == ' ')
		cub->no = ft_strtrim(&cub->map[i][j + 2], " ");
	else if (cub->map[i][j] == 'S' && cub->map[i][j + 1] == 'O'
			&& cub->map[i][j + 2] == ' ')
		cub->so = ft_strtrim(&cub->map[i][j + 2], " ");
	else if (cub->map[i][j] == 'W' && cub->map[i][j + 1] == 'E'
			&& cub->map[i][j + 2] == ' ')
		cub->we = ft_strtrim(&cub->map[i][j + 2], " ");
	else if (cub->map[i][j] == 'E' && cub->map[i][j + 1] == 'A'
		&& cub->map[i][j + 2] == ' ')
		cub->ea = ft_strtrim(&cub->map[i][j + 2], " ");
	else if (cub->map[i][j] == 'F' && cub->map[i][j + 1] == ' '
			&& ft_count_comma(cub->map[i]) == 2)
		cub->f = ft_split(&cub->map[i][j + 2], ',');
	else if (cub->map[i][j] == 'C' && cub->map[i][j + 1] == ' '
			&& ft_count_comma(cub->map[i]) == 2)
		cub->c = ft_split(&cub->map[i][j + 2], ',');
}

int	ft_check_for_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_data_of_map(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->map[++i] && i < 6)
	{
		if (cub->map[i][0] == 'N' || cub->map[i][0] == 'S'
			|| cub->map[i][0] == 'E' || cub->map[i][0] == 'W'
			|| cub->map[i][0] == 'F' || cub->map[i][0] == 'C')
			ft_set_data(cub, i, 0);
		else
			return (1);
	}

	if (!cub->no || !cub->so || !cub->we
		|| !cub->ea || !cub->f || !cub->c)
		return (1);
	ft_clear_floor_ceiling(cub);
	if (ft_check_for_space(cub->no) || ft_check_for_space(cub->so)
		|| ft_check_for_space(cub->we) || ft_check_for_space(cub->ea)
		|| ft_check_for_space(cub->f[0]) || ft_check_for_space(cub->f[1])
		|| ft_check_for_space(cub->f[2]) || ft_check_for_space(cub->c[0])
		|| ft_check_for_space(cub->c[1]) || ft_check_for_space(cub->c[2]))
		return (1);
	return (0);
}

int	ft_check_map(t_cub *cub, char *file_path)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->f = NULL;
	cub->c = NULL;
	int			i;

	i = 0;
	cub->map = get_map(file_path);
	while (cub->map && cub->map[i] && i < 6)
		i++;
	if (i < 5)
		return (EXIT_FAILURE);
	if (!ft_check_map_char(cub->map))
		return (EXIT_FAILURE);
	if (ft_check_data_of_map(cub))
		return (EXIT_FAILURE);
	if (!ft_check_map_wall(cub))
		return (EXIT_FAILURE);
	cub->floor_color = ft_atoi(cub->f[0]) << 16 | ft_atoi(cub->f[1]) << 8
		| ft_atoi(cub->f[2]);
	cub->ceiling_color = ft_atoi(cub->c[0]) << 16 | ft_atoi(cub->c[1]) << 8
		| ft_atoi(cub->c[2]);
	return (EXIT_SUCCESS);
}
