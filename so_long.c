/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:45:30 by ramoreno          #+#    #+#             */
/*   Updated: 2024/05/06 12:45:32 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

int main(void)
{
    void *mlx;
    t_data img;

    mlx = mlx_init();
    img.img = mlx_new_image(mlx, 1920, 1080);

    /*
    ** After creating an image, we can call `mlx_get_data_addr`, we pass
    ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
    ** then be set accordingly for the *current* data address.
    */
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    mlx_loop(mlx);
}
