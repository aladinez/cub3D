/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:54:26 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:13:02 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# define TILE_SIZE 64
# define SPEED 10
# define RADIAN (M_PI / 180)
# define ANG_QUARTER (M_PI / 2)

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "./get_next_line.h"
# include "./libft.h"

typedef struct	s_cast
{
	float	hx_intercept;
	float	hy_intercept;
	float	hx_step;
	float	hy_step;
	float	vx_intercept;
	float	vy_intercept;
	float	vx_step;
	float	vy_step;
	float	hx_wallhit;
	float	hy_wallhit;
	float	vx_wallhit;
	float	vy_wallhit;
	float	horizontal_wallhit;
	float	vertical_wallhit;
}				t_cast;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;

}				t_rgb;

typedef struct	s_sprite
{
	float	x;
	float	y;
	float	size;
	float	distance;
	float	angle;
	float	s_p_angle;
	float	off_x;
	float	off_y;
}				t_sprite;

typedef struct	s_bmp
{
	unsigned char	*buffer;
	unsigned char	header[54];
	unsigned char	planes;
	unsigned int	file_size;
	unsigned int	pixel_data_offset;
	unsigned int	header_size;
	unsigned int	bits_ppixel;
	unsigned int	image_size;
	int				row_bytes;
}				t_bmp;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	float		alpha;
	float		player_x;
	float		player_y;
	int			res_x;
	int			res_y;
	float		dis_projplan;
	int			f;
	int			c;
	char		*s;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			is_f;
	int			is_c;
	int			is_s;
	int			is_no;
	int			is_so;
	int			is_we;
	int			is_ea;
	int			is_r;
	int			is_map;
	float		ray_ang;
	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
	int			key_turn_left;
	int			key_turn_right;
	int			key_look_up;
	int			key_look_down;
	float		half_res_y;
	void		*text_img;
	int			*text_data[5];
	int			img_height;
	int			img_width;
	int			start;
	int			end;
	float		*rays;
	int			num_sprites;
	t_sprite	*sprite;
	t_bmp		bmp;
	t_rgb		rgb;
}				t_data;

char			**g_map;
int				g_x_squares;
int				g_y_squares;
int				g_bpp;
float			g_offset;
int				g_is_hor;
int				g_screenshot;

int				get_next_line(int fd, char **line);
int				check(char *buf);
void			my_bzero(void *s, size_t n);
void			*my_calloc(size_t count, size_t size);
char			*my_substr(char *s, unsigned int start, size_t len, int a);
size_t			my_strlen(const char *tab);
char			*my_strjoin(char *s1, char *s2);
int				f_u_moul(char **save, char **line, int fd, char **buf);
int				helper(char **line, char **save);
void			fill_map(char *argv);
void			fill_map1(int i, char *line);
void			read_info(t_data *data, char **str);
void			map_resolution(t_data *data, char *file);
int				ft_exit(int err_num);
void			verify_map_errors(void);
void			is_map_surrounded(void);
void			verify_map_chars(void);
void			check_missing_components(t_data *data);
void			find_p_position(t_data *data);
void			get_alpha_pxy(t_data *data, char c, int x, int y);
void			draw_game(t_data *data);
void			my_free(char **str);
void			my_pixel_put(t_data *data, int x, int y, int color);
int				ft_keypressed(int key, t_data *data);
int				ft_keyreleased(int key, t_data *data);
int				ft_render(t_data *data);
void			update_player_position(t_data *data);
int				check_wall(t_data *data, char c);
void			draw_wall(t_data *data, float ray, int x);
float			ray_cast(t_data *data, float teta);
int				is_right(float teta);
int				is_up(float teta);
int				ft_render(t_data *data);
float			normalize(float o);
int				wall_hit_check(int x, int y);
void			check_files_max_reso(t_data *data);
void			initialiser_a_zero(t_data *data);
void			allocate_for_map(t_data *data);
int				read_info_part1(t_data *data, char **str);
int				read_info_part2(t_data *data, char **str);
int				read_info_part3(t_data *data, char **str);
int				read_info_part4(t_data *data, char **str);
void			pick_texture(t_data *data, float y_text, int x, int y);
void			horizontal_casting(t_data *data, t_cast *cast, float teta);
void			vertical_casting(t_data *data, t_cast *cast, float teta);
int				check_wall_return(float x, float y);
void			get_texture_data(t_data *data);
void			draw_vertical_line1(t_data *data, int x, int i, int end);
void			draw_vertical_line2(t_data *data, int x, int i, int end);
void			find_sprites(t_data *data);
void			is_sprite(t_data *data, char *line);
void			ft_sprites(t_data *data);
void			sort_sprite(t_data *data);
float			s_distance_to_p(t_data *data, float x, float y);
void			normalize_sprite_ang(t_data *data, float rot_angle, int i);
void			draw_sprite(t_data *data, t_sprite sprite);
void			all_sprites_distances(t_data *data);
int				is_num(char *str, int a);
void			is_save(t_data *data, int argc, char **argv);
int				create_bmp(t_data *data);
void			int_to_rgb(t_data *data, unsigned int color);
void			save_bmp(t_data *data);
int				exit_game(t_data *data);
void			check_map_position(t_data *data);
void			check_missing_components(t_data *data);
void			file_handling(t_data *data, int argc, char **argv);

#endif
