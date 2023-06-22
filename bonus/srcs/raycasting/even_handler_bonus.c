/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:02:04 by woumecht          #+#    #+#             */
/*   Updated: 2023/06/22 11:40:30 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void    controlle_speed(t_cub *cub, int key)
{
    if (key == 69)
    {
        if (cub->speed == 25)
            printf("You are in the heigher speed !!!");
        else
            cub->speed++;
    }
    else
    {
        if (cub->speed == 5)
            printf("You are in the lower speed !!!\n");
        else
            cub->speed--;
    }
}

void    *animation_inc(void *arg)
{
    t_cub *cub;

    cub = (t_cub *)arg;
    int i = 0;
    pthread_mutex_lock(&cub->mut2);
    cub->flag_terminated = 1;
    pthread_mutex_unlock(&cub->mut2);
    while (i < 12)
    {
        usleep(70000);
        pthread_mutex_lock(&cub->mut);
        cub->guns_inc++;
        pthread_mutex_unlock(&cub->mut);
        i++;
    }
    pthread_mutex_lock(&cub->mut);
    cub->guns_inc = 1;
    pthread_mutex_unlock(&cub->mut);
    pthread_mutex_lock(&cub->mut2);
    cub->flag_terminated = 0;
    pthread_mutex_unlock(&cub->mut2);
    return (NULL);
}

void    view(t_cub *cub)
{
    printf("i am in view\n");
    if (cub->view == 2)
    {
        cub->view = 4;
        cub->dis_proj_plan = (WIDTH / cub->view) / tan(deg_to_rad(30));
    }
    else
    {
        cub->view = 2;
        cub->dis_proj_plan = (WIDTH / cub->view) / tan(deg_to_rad(30));
    }
    mlx_clear_window(cub->mlx, cub->mlx_win);
}

int event_handler(int key, t_cub *cub)
{
    int contr;
    
    pthread_mutex_lock(&cub->mut2);
    contr = cub->flag_terminated;
    pthread_mutex_unlock(&cub->mut2);
    printf("contr : %d\n", contr);
    if (key == 53)
    {
        kill_thread(cub);
        exit(0);
    }
    else if (key == 13 || key == 0 || key == 1 || key == 2 || key == 126 || key == 125)
    {   
        mlx_clear_window(cub->mlx, cub->mlx_win);
        movement(cub, key);
    }
    else if (key == 123 || key == 124)
    {
        mlx_clear_window(cub->mlx, cub->mlx_win);
        view_of_player(cub, key);
    }
    else if(key == 69 || key == 78)
        controlle_speed(cub, key);
    else if (key == 49 && contr == 0)
    {
        pthread_mutex_lock(&cub->mut2);
        contr = cub->flag_terminated;
        pthread_mutex_unlock(&cub->mut2);
        if (contr == 0)
        {
            // pthread_mutex_lock(&cub->mut2);
            // cub->flag_terminated = 1;
            // pthread_mutex_unlock(&cub->mut2);
            cub->th = malloc(sizeof(pthread_t));
            t_list *new = ft_lstnew(cub->th);
            ft_lstadd_back(&cub->ths, new);
            pthread_create(cub->th, NULL, animation_inc, (void *)cub);
        }
    }
    else if (key == 31)
        open_dor(cub);
    else if (key == 48)
        view(cub);
    else
        return (0);
    floor_ceil(cub);
    rays(cub);
    mini_map(cub);
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->data.img, 0, 0);
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->guns_arr[0], WIDTH / 2 - 250, HEIGHT - 281);
    build_msg(cub);
    return (0);
}
