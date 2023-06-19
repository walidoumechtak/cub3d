/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:38:14 by hbenfadd          #+#    #+#             */
/*   Updated: 2022/11/07 03:46:34 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short int	count_len(int n)
{
	short int	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0 && ++i)
		n = -n;
	while (n && ++i)
		n /= 10;
	return (i);
}

static void	convert(char *buff, int n, int len, char sign)
{
	while (len--)
	{
		if (sign && !len)
			break ;
		buff[len] = n % 10 + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	short int	len;
	char		*buff;
	char		sign;

	len = 0;
	sign = 0;
	buff = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_len(n);
	buff = (char *)malloc(len + 1);
	if (!buff)
		return (NULL);
	buff[len] = 0;
	if (n < 0)
	{
		buff[0] = '-';
		n *= -1;
		sign = 1;
	}
	convert(buff, n, len, sign);
	return (buff);
}
