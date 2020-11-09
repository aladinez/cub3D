/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:41:34 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:43 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	verify_map_errors(void)
{
	int		x;
	int		y;

	verify_map_chars();
	y = 0;
	while (y < g_y_squares)
	{
		if ((g_map[y][0] != ' ' && g_map[y][0] != '1') || (g_map[y]
			[g_x_squares - 1] != ' ' && g_map[y][g_x_squares - 1] != '1'))
			ft_exit(2);
		y++;
	}
	x = 0;
	while (x < g_x_squares)
	{
		if ((g_map[0][x] != ' ' && g_map[0][x] != '1')
	|| (g_map[g_y_squares - 1][x] != ' ' && g_map[g_y_squares - 1][x] != '1'))
			ft_exit(2);
		x++;
	}
	is_map_surrounded();
}

void	verify_map_chars(void)
{
	int		x;
	int		y;
	int		is_dupplicated;

	y = -1;
	is_dupplicated = 0;
	while (++y < g_y_squares)
	{
		x = -1;
		while (++x < g_x_squares)
		{
			if (g_map[y][x] != '0' && g_map[y][x] != '1' && g_map[y][x] != '2'
			&& g_map[y][x] != 'S' && g_map[y][x] != 'E' && g_map[y][x] != 'W'
			&& g_map[y][x] != 'N' && g_map[y][x] != ' ' && g_map[y][x] != '6')
				ft_exit(3);
			if (g_map[y][x] == 'N' || g_map[y][x] == 'S'
			|| g_map[y][x] == 'E' || g_map[y][x] == 'W')
				is_dupplicated++;
		}
	}
	if (is_dupplicated == 0 || is_dupplicated > 1)
		ft_exit(4);
}

void	is_map_surrounded(void)
{
	int		x;
	int		y;

	y = 1;
	while (y < g_y_squares - 1)
	{
		x = 1;
		while (x < g_x_squares - 1)
		{
			if (g_map[y][x] == '0' || g_map[y][x] == '2' || g_map[y][x] == 'N'
			|| g_map[y][x] == 'S' || g_map[y][x] == 'E' || g_map[y][x] == 'W'
			|| g_map[y][x] == '6')
			{
				if (g_map[y][x + 1] == ' ' || g_map[y][x - 1] == ' '
				|| g_map[y + 1][x] == ' ' || g_map[y - 1][x] == ' ')
					ft_exit(2);
			}
			x++;
		}
		y++;
	}
}

void	my_free(char **str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	str = NULL;
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	int		*var;
	int		index;
	int		new_y;

	var = (int*)mlx_get_data_addr(data->img_ptr, &g_bpp, &g_bpp, &g_bpp);
	if (x < data->res_x && x >= 0 && y < data->res_y && y >= 0)
	{
		if (g_screenshot == 1)
		{
			int_to_rgb(data, color);
			new_y = data->res_y - (y + 1);
			index = new_y * data->bmp.row_bytes + x * 3;
			data->bmp.buffer[index + 0] = data->rgb.b;
			data->bmp.buffer[index + 1] = data->rgb.g;
			data->bmp.buffer[index + 2] = data->rgb.r;
		}
		var[x + data->res_x * y] = color;
	}
}
