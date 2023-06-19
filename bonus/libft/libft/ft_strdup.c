/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:04:11 by hbenfadd          #+#    #+#             */
/*   Updated: 2022/10/11 13:05:02 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*buff;

	len = ft_strlen(s1);
	buff = (char *)malloc(len + 1);
	if (buff == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		buff[len] = ((char *)s1)[len];
		len ++;
	}
	buff[len] = 0;
	return (buff);
}
