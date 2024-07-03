/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:03:50 by ramoreno          #+#    #+#             */
/*   Updated: 2024/07/01 13:03:50 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minilibx_linux/mlx.h"
#include "lib_so_long.h"
#include <stdio.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	void *mlx;
	void *img;
	void *mlx_win;
	char *relative_path = "./img/xpm/coin.xpm";
	int img_width;
	int img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 420, "Hello world!");
	img = mlx_new_image(mlx, 720, 420);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
	{
		fprintf(stderr, "Error loading %s\n", relative_path);
		return 1;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}