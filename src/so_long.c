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
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 256));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	char	*filename;
	char	*extension;

	if (argc != 2)
	{
		ft_write("Error\nOnly 1 argument allowed\n");
		return (1);
	}
	filename = argv[1];
	extension = ft_strrchr(filename, '.');
	if (extension == NULL || ft_strncmp(extension, ".ber", 4) != 0)
	{
		ft_write("Error\nNot a .ber file\n");
		return (1);
	}
	ft_checkmap(filename);
}
