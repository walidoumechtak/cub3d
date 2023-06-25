/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenfadd <hbenfadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:00:56 by hbenfadd          #+#    #+#             */
/*   Updated: 2023/06/25 11:09:53 by hbenfadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include "../libft/inc/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define T_PI 6.28318530
# define ORANGE 0xff7f00
# define GOLD 0xFFD700
# define BLACK_GOLD 0x7c6900
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREN 0x00FF00
# define BLUE 0x7fcdff
# define RED 0xff0000
# define CARRE 30
# define WIDTH 1000
# define HEIGHT 800
# define R_VIEW 5

typedef struct s_player
{
	double		fov;
	double		p_fov;
	double		n_fov;
	int			xp;
	int			yp;
	double		pixel_x;
	double		pixel_y;
	int			move_speed;
	int			dir_vec;
	int			rotaion_speed;
	double		dir;
}				t_player;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

}				t_data;

typedef struct s_tex_size
{
	int			no_width;
	int			no_height;
	int			we_width;
	int			we_height;
	int			so_width;
	int			so_height;
	int			ea_width;
	int			ea_height;
}				t_tex_size;

typedef struct s_cub
{
	char		**map;
	char		*no;
	void		*no_ptr;
	char		*so;
	void		*so_ptr;
	char		*we;
	void		*we_ptr;
	char		*ea;
	void		*ea_ptr;
	char		**f;
	char		**c;
	int			floor_color;
	int			ceiling_color;
	char		*string_map;
	void		*mlx;
	void		*mlx_win;
	int			is_wall;
	double		ray_x;
	double		ray_y;
	double		ph_inter_x;
	double		ph_inter_y;
	double		dh_x_ray;
	double		dh_y_ray;
	double		pv_inter_x;
	double		pv_inter_y;
	double		dv_x_ray;
	double		dv_y_ray;
	double		ray_dir;
	double		dis_proj_plan;
	double		dis_v;
	double		dis_h;
	int			x_offset;
	int			y_offset;
	int			speed;
	t_tex_size	tex_size;
	t_player	ply;
	t_data		data;
}				t_cub;

/* Parssing Functions Prototypes */
int				ft_check_map(t_cub *cub, char *file_path);
char			**get_map(char *file_path);
int				ft_check_map_wall(t_cub *cub);
char			**ft_copy_map_to_rectangle_map(char **map);
void			ft_clear_floor_ceiling(t_cub *cub);
int				ft_count_comma(char *str);
int				ft_convert_color(char **str);

/* --------- raycasting prototype ------------*/

void			view_of_player(t_cub *cub, int key);
void			rays(t_cub *cub);
int				ray_casting(t_cub *cub);
int				ray_cast_ver(t_cub *cub);
int				ray_cast_hor(t_cub *cub);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			movement(t_cub *cub, int key);
void			move_player(t_cub *cub, double rot);
void			init_point_inter_ver(t_cub *cub);
void			init_point_inter_hor(t_cub *cub);
void			floor_ceil(t_cub *cub);
void			find_first_ray(t_cub *cub);
int				event_handler(int key, t_cub *cub);
void			draw_wal(t_cub *cub, char flag, int x, int WALL_TEXTR);
double			deg_to_rad(double deg);
double			rad_to_deg(double rad);
void			init_str(t_cub *cub);
int				x_size(t_cub *cub);
int				y_size(t_cub *cub);

#endif
