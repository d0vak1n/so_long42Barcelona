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

/*
Dimensiones elegidas para el juego, 1920x1080
1920/16 = 120
1080/9 = 120

Cada sprite sera de 120x120

*/
#include "../minilibx_linux/mlx.h"
#include "lib_so_long.h"
#include <stdio.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 256));
	*(unsigned int *)dst = color;
}

int main(char **argv, int argc)
{
	void *mlx;
	void *img;
	void *mlx_win;
	char *relative_path = "./img/xpm/cofre.xpm";
	int img_width;
	int img_height;

	checkmap();

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_new_image(mlx, 1920, 1080);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
	{
		fprintf(stderr, "Error loading %s\n", relative_path);
		return 1;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}