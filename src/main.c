/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:52:32 by aez-zaou          #+#    #+#             */
/*   Updated: 2020/11/09 19:03:02 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int argc, char **argv)
{
	t_data data;

	file_handling(&data, argc, argv);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr
								, data.res_x, data.res_y, "Cub3D");
	data.img_ptr = mlx_new_image(data.mlx_ptr, data.res_x, data.res_y);
	data.img_data = (int *)mlx_get_data_addr(data.img_ptr
								, &g_bpp, &g_bpp, &g_bpp);
	get_texture_data(&data);
	is_save(&data, argc, argv);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 2, 0, ft_keypressed, &data);
	mlx_hook(data.win_ptr, 3, 0, ft_keyreleased, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_game, &data);
	mlx_loop_hook(data.mlx_ptr, ft_render, &data);
	mlx_loop(data.mlx_ptr);
}

void	file_handling(t_data *data, int argc, char **argv)
{
	if (argc == 1 || argc > 3)
		ft_exit(9);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) != 0
	|| argv[2][6] != 0))
		ft_exit(9);
	initialiser_a_zero(data);
	if (argv[1])
		map_resolution(data, argv[1]);
	else
		ft_exit(6);
	allocate_for_map(data);
	data->half_res_y = data->res_y / 2;
	data->dis_projplan = (data->res_x / 2) / tanf(30 * RADIAN);
	fill_map(argv[1]);
	verify_map_errors();
	check_missing_components(data);
	check_files_max_reso(data);
	find_p_position(data);
	data->rays = (float *)malloc(data->res_x * sizeof(float));
	find_sprites(data);
}

int		exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}
