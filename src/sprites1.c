/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 05:47:48 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:56 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	all_sprites_distances(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_sprites)
	{
		data->sprite[i].distance = (int)s_distance_to_p(data
		, data->sprite[i].x, data->sprite[i].y);
		i++;
	}
}

void	find_sprites(t_data *data)
{
	int x;
	int y;
	int	i;

	i = data->num_sprites - 1;
	y = 0;
	while (y < g_y_squares)
	{
		x = 0;
		while (x < g_x_squares)
		{
			if (g_map[y][x] == '2')
			{
				data->sprite[i].x = x * TILE_SIZE + (TILE_SIZE / 2);
				data->sprite[i].y = y * TILE_SIZE + (TILE_SIZE / 2);
				i--;
			}
			x++;
		}
		y++;
	}
}

float	s_distance_to_p(t_data *data, float x, float y)
{
	float dx;
	float dy;

	dx = (int)data->player_x - x;
	dy = (int)data->player_y - y;
	return (sqrtf(powf(dx, 2) + powf(dy, 2)));
}
