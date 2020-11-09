/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:13:37 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:32 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	initialiser_a_zero(t_data *data)
{
	g_x_squares = 0;
	g_y_squares = 0;
	data->is_no = 0;
	data->is_r = 0;
	data->is_s = 0;
	data->is_so = 0;
	data->is_we = 0;
	data->is_f = 0;
	data->is_c = 0;
	data->is_ea = 0;
	data->is_map = 0;
	data->key_up = 0;
	data->key_down = 0;
	data->key_right = 0;
	data->key_left = 0;
	data->key_turn_right = 0;
	data->key_turn_left = 0;
	data->key_look_up = 0;
	data->num_sprites = 0;
	g_screenshot = 0;
}

void	check_missing_components(t_data *data)
{
	if (data->is_c == 0 || data->is_ea == 0 || data->is_f == 0
	|| data->is_no == 0 || data->is_r == 0 || data->is_s == 0
	|| data->is_so == 0 || data->is_we == 0)
		ft_exit(5);
}

void	check_map_position(t_data *data)
{
	if (data->is_c == 0 || data->is_ea == 0 || data->is_f == 0
	|| data->is_no == 0 || data->is_r == 0 || data->is_s == 0
	|| data->is_so == 0 || data->is_we == 0)
		ft_exit(7);
}

int		check_wall(t_data *data, char c)
{
	float x;
	float y;

	if (c == 'U')
	{
		x = data->player_x + cosf(data->alpha) * SPEED * 2;
		y = data->player_y - sinf(data->alpha) * SPEED * 2;
	}
	else if (c == 'D')
	{
		x = data->player_x - cosf(data->alpha) * SPEED * 2;
		y = data->player_y + sinf(data->alpha) * SPEED * 2;
	}
	else if (c == 'R')
	{
		x = data->player_x + cosf(data->alpha - ANG_QUARTER) * SPEED * 2;
		y = data->player_y - sinf(data->alpha - ANG_QUARTER) * SPEED * 2;
	}
	else
	{
		x = data->player_x + cosf(data->alpha + ANG_QUARTER) * SPEED * 2;
		y = data->player_y - sinf(data->alpha + ANG_QUARTER) * SPEED * 2;
	}
	return (check_wall_return(x, y));
}

int		check_wall_return(float x, float y)
{
	if (g_map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1'
		|| g_map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '2')
		return (0);
	else
		return (1);
}
