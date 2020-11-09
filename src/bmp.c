/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:17:45 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 18:47:57 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	is_save(t_data *data, int argc, char **argv)
{
	char	*save;

	save = "--save";
	if (argc == 3)
	{
		if ((ft_strlen(argv[2]) != ft_strlen(save)) ||
		ft_strncmp(save, argv[2], ft_strlen(save)))
			ft_exit(9);
		g_screenshot = 1;
		create_bmp(data);
		draw_game(data);
		ft_sprites(data);
		save_bmp(data);
		exit(0);
	}
}

int		create_bmp(t_data *data)
{
	unsigned int width;
	unsigned int height;

	width = data->res_x;
	height = data->res_y;
	data->bmp.bits_ppixel = 24;
	data->bmp.row_bytes = (unsigned int)(((data->bmp.bits_ppixel
						* (unsigned int)data->res_x + 31) / 32) * 4);
	data->bmp.image_size = data->bmp.row_bytes * data->res_y;
	data->bmp.pixel_data_offset = 54;
	data->bmp.header_size = 40;
	data->bmp.file_size = 54 + data->bmp.image_size;
	data->bmp.planes = 1;
	ft_bzero(data->bmp.header, 54);
	ft_memcpy(data->bmp.header, &"BM", 2);
	ft_memcpy(data->bmp.header + 2, &data->bmp.file_size, 4);
	ft_memcpy(data->bmp.header + 10, &data->bmp.pixel_data_offset, 4);
	ft_memcpy(data->bmp.header + 14, &data->bmp.header_size, 4);
	ft_memcpy(data->bmp.header + 18, &width, 4);
	ft_memcpy(data->bmp.header + 22, &height, 4);
	ft_memcpy(data->bmp.header + 26, &data->bmp.planes, 2);
	ft_memcpy(data->bmp.header + 28, &data->bmp.bits_ppixel, 2);
	ft_memcpy(data->bmp.header + 34, &data->bmp.image_size, 4);
	data->bmp.buffer = malloc(data->bmp.image_size);
	return (0);
}

void	int_to_rgb(t_data *data, unsigned int color)
{
	data->rgb.r = color / 65536;
	color -= data->rgb.r * 65536;
	data->rgb.g = color / 256;
	data->rgb.b = color % 256;
}

void	save_bmp(t_data *data)
{
	int	fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
	if (fd == -1)
		return ;
	write(fd, data->bmp.header, 54);
	write(fd, data->bmp.buffer, data->bmp.image_size);
	close(fd);
	free(data->bmp.buffer);
}
