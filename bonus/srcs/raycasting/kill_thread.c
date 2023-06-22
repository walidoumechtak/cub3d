/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:10:19 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/22 21:43:04 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	kill_thread(t_cub *cub)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(cub->ths);
	printf("size is : %d\n", size);
	while (cub->ths != NULL)
	{
		pthread_join(*(pthread_t *)(cub->ths->content), NULL);
		i++;
		cub->ths = cub->ths->next;
	}
}
