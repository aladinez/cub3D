/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 06:12:29 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 20:22:43 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	find_p_position(t_data *data)
{
	int i;
	int j;

	j = 0;
	while (j < g_y_squares)
	{
		i = 0;
		while (i < g_x_squares)
		{
			if (ft_isalpha(g_map[j][i]))
				get_alpha_pxy(data, g_map[j][i], i * TILE_SIZE, j * TILE_SIZE);
			i++;
		}
		j++;
	}
}

void	get_alpha_pxy(t_data *data, char c, int x, int y)
{
	data->player_x = x + (TILE_SIZE / 2);
	data->player_y = y + (TILE_SIZE / 2);
	if (c == 'N')
		data->alpha = 90 * RADIAN;
	else if (c == 'S')
		data->alpha = 270 * RADIAN;
	else if (c == 'E')
		data->alpha = 0;
	else if (c == 'W')
		data->alpha = M_PI;
}

int		is_num(char *str, int a)
{
	int i;
	int num;

	i = 0;
	num = ft_atoi(str);
	if ((a == 1 && num > 255) || num < 0)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
