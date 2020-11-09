/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 03:50:02 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:56:16 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	read_info(t_data *data, char **str)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = read_info_part1(data, str);
	b = read_info_part2(data, str);
	c = read_info_part3(data, str);
	d = read_info_part4(data, str);
	if (a && b && c && d && (str[0][0] != '1' && str[0][0] != ' '
		&& str[0][0] != '0' && str[0][0] != '2' && str[0][0] != '6'))
		ft_exit(3);
	my_free(str);
}

int		read_info_part4(t_data *data, char **str)
{
	char	**color;

	if (str[0][0] == 'C')
	{
		if (data->is_c == 1 || str[2])
			ft_exit(1);
		data->is_c = 1;
		color = ft_split(str[1], ',');
		if (is_num(color[0], 1) || is_num(color[1], 1) || is_num(color[2], 1))
			ft_exit(3);
		data->c = 65536 * ft_atoi(color[0]) + 256 * ft_atoi(color[1]);
		data->c += ft_atoi(color[2]);
		my_free(color);
	}
	else
		return (1);
	return (0);
}

int		read_info_part3(t_data *data, char **str)
{
	char	**color;

	if (str[0][0] == 'S' && !str[0][1])
	{
		if (data->is_s == 1 || str[2])
			ft_exit(1);
		data->is_s = 1;
		data->s = ft_substr(str[1], 0, ft_strlen(str[1]));
	}
	else if (str[0][0] == 'F')
	{
		if (data->is_f == 1 || str[2])
			ft_exit(1);
		data->is_f = 1;
		color = ft_split(str[1], ',');
		if (is_num(color[0], 1) || is_num(color[1], 1) || is_num(color[2], 1))
			ft_exit(3);
		data->f = 65536 * ft_atoi(color[0]) + 256 * ft_atoi(color[1]);
		data->f += ft_atoi(color[2]);
		my_free(color);
	}
	else
		return (1);
	return (0);
}

int		read_info_part2(t_data *data, char **str)
{
	if (str[0][0] == 'S' && str[0][1] == 'O')
	{
		if (data->is_so == 1 || str[2])
			ft_exit(1);
		data->is_so = 1;
		data->so = ft_substr(str[1], 0, ft_strlen(str[1]));
	}
	else if (str[0][0] == 'E' && str[0][1] == 'A')
	{
		if (data->is_ea == 1 || str[2])
			ft_exit(1);
		data->is_ea = 1;
		data->ea = ft_substr(str[1], 0, ft_strlen(str[1]));
	}
	else if (str[0][0] == 'W' && str[0][1] == 'E')
	{
		if (data->is_we == 1 || str[2])
			ft_exit(1);
		data->is_we = 1;
		data->we = ft_substr(str[1], 0, ft_strlen(str[1]));
	}
	else
		return (1);
	return (0);
}

int		read_info_part1(t_data *data, char **str)
{
	if (str[0][0] == 'R')
	{
		if (data->is_r == 1 || str[3])
			ft_exit(1);
		if (is_num(str[1], 0) || is_num(str[2], 0))
			ft_exit(3);
		data->is_r = 1;
		data->res_x = ft_atoi(str[1]);
		data->res_y = ft_atoi(str[2]);
		if (data->res_x > 2560)
			data->res_x = 2560;
		if (data->res_y > 1440)
			data->res_y = 1440;
	}
	else if (str[0][0] == 'N' && str[0][1] == 'O')
	{
		if (data->is_no == 1 || str[2])
			ft_exit(1);
		data->is_no = 1;
		data->no = ft_substr(str[1], 0, ft_strlen(str[1]));
	}
	else
		return (1);
	return (0);
}
