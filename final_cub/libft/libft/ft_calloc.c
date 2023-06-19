/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:07:07 by hbenfadd          #+#    #+#             */
/*   Updated: 2022/11/06 20:59:49 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	buff = malloc(count * size);
	if (buff == NULL)
		return (NULL);
	ft_bzero(buff, count * size);
	return (buff);
}
