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
#include "./minilibx_linux/mlx.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void cuadrado(t_data *data, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			my_mlx_pixel_put(data, i, 0, color);
			j++;
		}
		i++;
	}
}

void lgtbi(t_data *data, int x, int y)
{
	int i = 0;
	int j = 0;
	int flagcolor1;
	int flagcolor2;
	int flagcolor3;
	int flagcolor4;
	int flagcolor5;
	int flagcolor6;

	flagcolor1 = 0x00FF0000;
	flagcolor2 = 0x00FFA500;
	flagcolor3 = 0x00FFFF00;
	flagcolor4 = 0x00008F39;
	flagcolor5 = 0x000000FF;
	flagcolor6 = 0x0078288C;


	while (j < 1 * (y / 6))
	{
		i = 0;
		while (i < x)
		{
			my_mlx_pixel_put(data, i, j, flagcolor1);
			i++;
		}
		j++;
	}

	while (j < 2 * (y / 6))
	{
		i = 0;
		while (i < x)
		{
			my_mlx_pixel_put(data, i, j, flagcolor2);
			i++;
		}
		j++;
	}

	while (j < 3 * (y / 6))
	{
		i = 0;
		while (i < x)
		{
			my_mlx_pixel_put(data, i, j, flagcolor3);
			i++;
		}
		j++;
	}

	while (j < 4 * (y / 6))
	{
		i = 0;
		while (i < x)
		{
			my_mlx_pixel_put(data, i, j, flagcolor4);
			i++;
		}
		j++;
	}

	while (j < 5 * (y / 6))
	{
		i = 0;
		while (i < x)
		{
			my_mlx_pixel_put(data, i, j, flagcolor5);
			i++;
		}
		j++;
	}

	while (j < 6 * (y / 6))
	{
		i = 0;
		while (i < x)
		{
			my_mlx_pixel_put(data, i, j, flagcolor6);
			i++;
		}
		j++;
	}
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hola Mundo :D");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	// cuadrado(&img, 0x00FF0000);
	lgtbi(&img, 1920, 1080);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
