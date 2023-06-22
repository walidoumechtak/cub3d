/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:36:52 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/08 17:50:05 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

/**
 * @brief append the buffer to the string and return the new string
 * @param str the string to append to it the buffer
 * @param buffer the buffer to append to the string str
 * @return the new string or NULL if an error occured
*/
static char	*_append_buffer_to_str(char *str, char *buffer)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, buffer);
	if (!str)
		return (ft_putstr_fd("Error\nFailed to join strings\n", 2), NULL);
	free(tmp);
	return (str);
}

/**
 * @brief read the map from the file and return it as a string
 * @param fd file descriptor of the file that contains the map
 * @return string that contains the map or NULL if an error occured
*/
static char	*read_map(int fd)
{
	char	*buff;
	char	*tmp;
	int		flag;

	tmp = NULL;
	buff = malloc(sizeof(char) * 2);
	if (!buff)
		return (ft_putstr_fd("Error\nFailed to allocate memory\n", 2), NULL);
	ft_bzero(buff, 2);
	while (1)
	{
		flag = read(fd, buff, 1);
		if (flag == -1)
			return (ft_putstr_fd("Error\nFailed to read file\n", 2), NULL);
		if (flag == 0)
			break ;
		tmp = _append_buffer_to_str(tmp, buff);
		if (!tmp)
			return (NULL);
	}
	free(buff);
	return (tmp);
}

/**
 * @brief get the map from the file and return it as a 2D array of char
 * @param file_path path to the file that contains the map
 * @return 2D array of char that contains the map or NULL if an error occured
*/
char	**get_map(char *file_path)
{
	int		fd;
	char	*tmp;
	char	**map;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nFailed to open file\n", 2), NULL);
	tmp = read_map(fd);
	if (!tmp)
		return (NULL);
	map = ft_split(tmp, '\n');
	if (!map)
		return (ft_putstr_fd("Error\nFailed to split string\n", 2), NULL);
	free(tmp);
	return (map);
}