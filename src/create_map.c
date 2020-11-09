/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 05:07:36 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:14:14 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	map_resolution(t_data *data, char *file)
{
	char	*line;
	int		i;
	int		a;
	int		fd;

	fd = open(file, O_RDONLY);
	while ((i = get_next_line(fd, &line)) >= 0)
	{
		if (*line != 0)
			read_info(data, ft_split(line, ' '));
		if (*line == '1' || *line == ' ' || *line == '0' || *line == '2')
		{
			data->is_map = 1;
			check_map_position(data);
			g_y_squares++;
			a = ft_strlen(line);
			g_x_squares = g_x_squares < a ? a : g_x_squares;
			is_sprite(data, line);
		}
		free(line);
		if (i == 0)
			break ;
	}
	if (data->is_map == 0)
		ft_exit(8);
}

void	allocate_for_map(t_data *data)
{
	int	i;

	i = 0;
	g_map = (char **)malloc(g_y_squares * sizeof(char *));
	while (i < g_y_squares)
	{
		g_map[i] = (char *)malloc(g_x_squares * sizeof(char));
		i++;
	}
	data->sprite = (t_sprite *)malloc(data->num_sprites * sizeof(t_sprite));
}

void	is_sprite(t_data *data, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '2')
			data->num_sprites++;
		i++;
	}
}

void	fill_map(char *argv)
{
	char	*line;
	int		i;
	int		ret;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (*line == 0)
		{
			free(line);
			if (!ret)
				break ;
			continue;
		}
		if (*line == '1' || *line == ' ' || *line == '2'
			|| *line == '0' || *line == '6')
		{
			fill_map1(i, line);
			i++;
		}
		free(line);
	}
}

void	fill_map1(int i, char *line)
{
	int		j;

	j = 0;
	while (j < (int)ft_strlen(line) && (g_map[i][j] = line[j]))
		j++;
	while (j < g_x_squares && (g_map[i][j] = ' '))
		j++;
}
