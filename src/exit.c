/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 04:25:21 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:24 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_exit(int err_num)
{
	ft_putstr_fd("Error\n", 1);
	if (err_num == 1)
		ft_putstr_fd("Dupplicated data in the map.\n", 2);
	else if (err_num == 2)
		ft_putstr_fd("Map not surrounded by walls.\n", 2);
	else if (err_num == 3)
		ft_putstr_fd("Invalid character in map.\n", 2);
	else if (err_num == 4)
		ft_putstr_fd("No player or dupplicated player.\n", 2);
	else if (err_num == 5)
		ft_putstr_fd("Missing map component.\n", 2);
	else if (err_num == 6)
		ft_putstr_fd("Missing file.\n", 2);
	else if (err_num == 7)
		ft_putstr_fd("Map is not the last.\n", 2);
	else if (err_num == 8)
		ft_putstr_fd("No map.\n", 2);
	else if (err_num == 9)
		ft_putstr_fd("Arguments error.\n", 2);
	exit(0);
	return (0);
}

int		wall_hit_check(int x, int y)
{
	if (x >= 0 && y >= 0 && x < TILE_SIZE * g_x_squares
	&& y < TILE_SIZE * g_y_squares)
	{
		if (g_map[y / TILE_SIZE][x / TILE_SIZE] == '1'
			|| g_map[y / TILE_SIZE][x / TILE_SIZE] == '6')
			return (1);
		else
			return (0);
	}
	return (-1);
}

int		is_up(float teta)
{
	if (teta >= 0 && teta <= M_PI)
		return (1);
	else
		return (0);
}

int		is_right(float teta)
{
	if (teta >= 0.5 * M_PI && teta <= 1.5 * M_PI)
		return (0);
	else
		return (1);
}

float	normalize(float o)
{
	if (o > 360)
	{
		o -= 360;
	}
	else if (o < 0)
	{
		o += 360;
	}
	return (o);
}
