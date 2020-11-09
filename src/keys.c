/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:53:02 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:35 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_keypressed(int key, t_data *data)
{
	if (key == 53)
		exit_game(data);
	else if (key == 124)
		data->key_turn_right = -2;
	else if (key == 123)
		data->key_turn_left = 2;
	else if (key == 13)
		data->key_up = 1;
	else if (key == 1)
		data->key_down = -1;
	else if (key == 0)
		data->key_left = 1;
	else if (key == 2)
		data->key_right = -1;
	else if (key == 126)
		data->key_look_up = 8;
	else if (key == 125)
		data->key_look_up = -8;
	return (0);
}

int		ft_keyreleased(int key, t_data *data)
{
	if (key == 124)
		data->key_turn_right = 0;
	else if (key == 123)
		data->key_turn_left = 0;
	else if (key == 13)
		data->key_up = 0;
	else if (key == 1)
		data->key_down = 0;
	else if (key == 0)
		data->key_left = 0;
	else if (key == 2)
		data->key_right = 0;
	else if (key == 125 || key == 126)
		data->key_look_up = 0;
	return (0);
}

int		ft_render(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->res_x, data->res_y);
	data->img_data = (int *)mlx_get_data_addr(data->img_ptr
											, &g_bpp, &g_bpp, &g_bpp);
	update_player_position(data);
	if (data->half_res_y + data->key_look_up >= data->res_y / 4
	&& data->half_res_y + data->key_look_up <= data->res_y * 3 / 4)
		data->half_res_y += data->key_look_up;
	draw_game(data);
	ft_sprites(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

void	update_player_position(t_data *data)
{
	data->alpha += data->key_turn_left * RADIAN;
	data->alpha += data->key_turn_right * RADIAN;
	if (data->key_up && check_wall(data, 'U'))
	{
		data->player_x += cosf(data->alpha) * SPEED;
		data->player_y -= sinf(data->alpha) * SPEED;
	}
	if (data->key_down && check_wall(data, 'D'))
	{
		data->player_x -= cosf(data->alpha) * SPEED;
		data->player_y += sinf(data->alpha) * SPEED;
	}
	if (data->key_left && check_wall(data, 'L'))
	{
		data->player_x += cosf(data->alpha + ANG_QUARTER) * SPEED;
		data->player_y -= sinf(data->alpha + ANG_QUARTER) * SPEED;
	}
	if (data->key_right && check_wall(data, 'R'))
	{
		data->player_x += cosf(data->alpha - ANG_QUARTER) * SPEED;
		data->player_y -= sinf(data->alpha - ANG_QUARTER) * SPEED;
	}
	data->alpha = fmod(data->alpha, 2 * M_PI);
	if (data->alpha < 0)
		data->alpha = (2 * M_PI) + data->alpha;
}
