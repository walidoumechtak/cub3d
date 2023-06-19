/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:43:18 by hbenfadd          #+#    #+#             */
/*   Updated: 2022/11/07 03:59:45 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char	const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if ((*str != c && str[1] == 0)
			|| (*str != c && str[1] == c))
			count++;
		str++;
	}
	return (count);
}

static size_t	len_word(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str != c)
		{
			while (*str != c && *str)
			{
				str++;
				len++;
			}
			return (len);
		}
		str++;
	}
	return (len);
}

static char	**free_all(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;
	size_t	count;
	size_t	w;
	size_t	a;

	if (!s)
		return (NULL);
	w = 0;
	count = count_word(s, c);
	a = count;
	buff = (char **)malloc((count + 1) * sizeof(char *));
	if (!buff)
		return (NULL);
	while (a--)
	{
		while (*s == c)
			s++;
		count = len_word(s, c);
		buff[w] = ft_substr(s, 0, count);
		if (!buff[w++])
			return (free_all(buff));
		s += count;
	}
	buff[w] = NULL;
	return (buff);
}
