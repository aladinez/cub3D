/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:59:02 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:50 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

float	ray_cast(t_data *data, float teta)
{
	t_cast cast;

	cast.hy_intercept = (int)(data->player_y / TILE_SIZE) * TILE_SIZE;
	cast.vx_intercept = (int)(data->player_x / TILE_SIZE) * TILE_SIZE;
	horizontal_casting(data, &cast, teta);
	vertical_casting(data, &cast, teta);
	cast.horizontal_wallhit = sqrt((data->player_y - cast.hy_wallhit)
	* (data->player_y - cast.hy_wallhit) + (data->player_x - cast.hx_wallhit)
	* (data->player_x - cast.hx_wallhit));
	cast.vertical_wallhit = sqrt((data->player_y - cast.vy_wallhit)
	* (data->player_y - cast.vy_wallhit) + (data->player_x - cast.vx_wallhit)
	* (data->player_x - cast.vx_wallhit));
	g_is_hor = 0;
	if (cast.vertical_wallhit > cast.horizontal_wallhit && (g_is_hor = 1))
	{
		g_offset = fmod(cast.hx_wallhit, data->img_width);
		return (cast.horizontal_wallhit);
	}
	else
	{
		g_offset = fmod(cast.vy_wallhit, data->img_width);
		return (cast.vertical_wallhit);
	}
}

void	horizontal_casting(t_data *data, t_cast *cast, float teta)
{
	int direction;
	int a;

	if ((direction = is_up(teta)) == 0)
		cast->hy_intercept += TILE_SIZE;
	if ((direction = is_up(teta)) == 1)
		a = -1;
	else
		a = 0;
	cast->hx_intercept = data->player_x
					+ (data->player_y - cast->hy_intercept) / tanf(teta);
	cast->hy_step = TILE_SIZE;
	if ((direction = is_up(teta)) == 1)
		cast->hy_step *= -1;
	cast->hx_step = TILE_SIZE / tanf(teta);
	if ((direction = is_up(teta)) == 0)
		cast->hx_step *= -1;
	cast->hx_wallhit = cast->hx_intercept;
	cast->hy_wallhit = cast->hy_intercept;
	while (wall_hit_check((int)cast->hx_wallhit,
	(int)cast->hy_wallhit + a) == 0)
	{
		cast->hx_wallhit += cast->hx_step;
		cast->hy_wallhit += cast->hy_step;
	}
}

void	vertical_casting(t_data *data, t_cast *cast, float teta)
{
	int direction;
	int a;

	if ((direction = is_right(teta)) == 1)
		cast->vx_intercept += TILE_SIZE;
	if ((direction = is_right(teta)) == 0)
		a = -1;
	else
		a = 0;
	cast->vy_intercept = data->player_y
					+ (data->player_x - cast->vx_intercept) * tanf(teta);
	cast->vx_step = TILE_SIZE;
	if ((direction = is_right(teta)) == 0)
		cast->vx_step *= -1;
	cast->vy_step = TILE_SIZE * tanf(teta);
	if ((direction = is_right(teta)) == 1)
		cast->vy_step *= -1;
	cast->vx_wallhit = cast->vx_intercept;
	cast->vy_wallhit = cast->vy_intercept;
	while (wall_hit_check((int)cast->vx_wallhit + a,
	(int)cast->vy_wallhit) == 0)
	{
		cast->vx_wallhit += cast->vx_step;
		cast->vy_wallhit += cast->vy_step;
	}
}

void	check_files_max_reso(t_data *data)
{
	if (open(data->no, O_RDONLY) < 0 || open(data->so, O_RDONLY) < 0
		|| open(data->ea, O_RDONLY) < 0 || open(data->we, O_RDONLY) < 0
		|| open(data->s, O_RDONLY) < 0)
		ft_exit(6);
	if (data->res_x > 2560)
		data->res_x = 2560;
	if (data->res_y > 1440)
		data->res_y = 1440;
}

void	get_texture_data(t_data *data)
{
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, data->no
					, &data->img_width, &data->img_height);
	data->text_data[0] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, data->so
					, &data->img_width, &data->img_height);
	data->text_data[1] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, data->ea
					, &data->img_width, &data->img_height);
	data->text_data[2] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, data->we
					, &data->img_width, &data->img_height);
	data->text_data[3] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, data->s
					, &data->img_width, &data->img_height);
	data->text_data[4] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
}
