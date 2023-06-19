/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:16:49 by hbenfadd          #+#    #+#             */
/*   Updated: 2022/10/31 00:17:33 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(*needle) || (!haystack && !len))
		return ((char *)haystack);
	while (haystack[i] && i < len && len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j]
			&& needle[j] && i + j < len)
		{
			j++;
			if (!needle[j])
				return ((char *)haystack + i);
		}
		if (i + j == len)
			break ;
		i++;
	}
	return (NULL);
}
