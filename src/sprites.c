/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:01:38 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:53 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	normalize_sprite_ang(t_data *data, float rot_angle, int i)
{
	while (data->sprite[i].angle - rot_angle > M_PI)
		data->sprite[i].angle -= 2 * M_PI;
	while (data->sprite[i].angle - rot_angle < -M_PI)
		data->sprite[i].angle += 2 * M_PI;
}

void	ft_sprites(t_data *data)
{
	int		i;
	float	rot_angle;

	all_sprites_distances(data);
	sort_sprite(data);
	rot_angle = -1 * data->alpha;
	i = 0;
	while (i < data->num_sprites)
	{
		data->sprite[i].angle = atan2f(data->sprite[i].y - data->player_y
								, data->sprite[i].x - data->player_x);
		normalize_sprite_ang(data, rot_angle, i);
		data->sprite[i].size = data->res_x / data->sprite[i].distance
								* (float)TILE_SIZE;
		data->sprite[i].off_x = (int)((data->sprite[i].angle / RADIAN
						- (rot_angle) / RADIAN) * data->res_x / (60)
						+ (data->res_x / 2 - data->sprite[i].size / 2));
		data->sprite[i].off_y = (int)(data->half_res_y
								- data->sprite[i].size / 2);
		draw_sprite(data, data->sprite[i]);
		i++;
	}
}

void	draw_sprite(t_data *data, t_sprite sprite)
{
	int		i;
	int		j;
	int		color;

	i = -1;
	while (++i < (int)sprite.size)
	{
		if (sprite.off_x + i < 0 || sprite.off_x + i > data->res_x)
			continue ;
		if (data->rays[(int)(sprite.off_x + i - 1)] <= sprite.distance)
			continue ;
		j = -1;
		while (++j < (int)sprite.size)
		{
			if (sprite.off_y + j < 0 || sprite.off_y + j > data->res_y)
				continue ;
			color = data->text_data[4][(int)(data->img_width
			* (data->img_height * j / (int)(sprite.size))
			+ (data->img_width * i / (int)sprite.size))];
			if (color != data->text_data[4][0])
				my_pixel_put(data, ((int)sprite.off_x + i)
				, ((int)sprite.off_y + j), color);
		}
	}
}

void	sort_sprite(t_data *data)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = -1;
	while (++i < data->num_sprites)
	{
		j = i;
		while (++j < data->num_sprites)
		{
			if (data->sprite[i].distance < data->sprite[j].distance)
			{
				temp = data->sprite[i];
				data->sprite[i] = data->sprite[j];
				data->sprite[j] = temp;
			}
		}
	}
}
