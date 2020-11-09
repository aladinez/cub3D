/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 04:44:25 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:19 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	draw_game(t_data *data)
{
	int		i;
	float	teta;
	float	incr;
	float	ray;

	teta = -30;
	i = data->res_x - 1;
	incr = (float)60 / (float)data->res_x;
	while (teta <= 30)
	{
		ray = ray_cast(data, normalize((data->alpha
		* (180 / M_PI) + teta)) * (RADIAN));
		data->rays[i - 1] = ray;
		ray *= cosf(data->alpha - (((data->alpha
		* (180 / M_PI) + teta)) * (RADIAN)));
		data->ray_ang = normalize((data->alpha * 180 / M_PI) + teta);
		draw_wall(data, ray, i);
		teta += incr;
		i--;
	}
}

void	draw_wall(t_data *data, float ray, int x)
{
	float	wall_height;
	int		y;
	float	y_text;
	float	factor;

	y_text = 0;
	wall_height = (TILE_SIZE / ray) * data->dis_projplan;
	factor = (float)data->img_height / wall_height;
	data->start = data->half_res_y - (wall_height / 2);
	data->end = data->half_res_y + (wall_height / 2);
	data->start = data->start < 0 ? 0 : data->start;
	data->end = data->end > data->res_y ? data->res_y : data->end;
	draw_vertical_line1(data, x, -1, data->start);
	y = data->start;
	while (y < data->end)
	{
		pick_texture(data, y_text, x, y);
		y_text = (y + ((int)wall_height / 2) - (data->half_res_y)) * factor;
		y++;
	}
	draw_vertical_line2(data, x, data->end, data->res_y - 2);
}

void	draw_vertical_line1(t_data *data, int x, int i, int end)
{
	while (++i < end)
		my_pixel_put(data, x, i, data->c);
}

void	draw_vertical_line2(t_data *data, int x, int i, int end)
{
	while (++i < end)
		my_pixel_put(data, x, i, data->f);
}

void	pick_texture(t_data *data, float y_text, int x, int y)
{
	int color;

	color = 0;
	if (g_is_hor && is_up(data->ray_ang * RADIAN))
		color = data->text_data[0][(int)((int)y_text
				* data->img_height + (int)g_offset)];
	else if (g_is_hor && !is_up(data->ray_ang * RADIAN))
		color = data->text_data[1][(int)((int)y_text
				* data->img_height + (int)g_offset)];
	else if (!g_is_hor && is_right(data->ray_ang * RADIAN))
		color = data->text_data[2][(int)((int)y_text
				* data->img_height + (int)g_offset)];
	else if (!g_is_hor && !is_right(data->ray_ang * RADIAN))
		color = data->text_data[3][(int)((int)y_text
				* data->img_height + (int)g_offset)];
	my_pixel_put(data, x, y, color);
}
