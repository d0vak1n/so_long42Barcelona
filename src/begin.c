/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:49:51 by ramoreno          #+#    #+#             */
/*   Updated: 2024/09/17 17:49:55 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"

void begin() {
    
	void *mlx;
	void *img;
	void *mlx_win;
	char *relative_path = "./img/xpm/cofre.xpm";
	int img_width;
	int img_height;

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

    printf("Drawing has begun!\n");
}
