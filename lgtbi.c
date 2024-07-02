/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgtbi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:21:17 by ramoreno          #+#    #+#             */
/*   Updated: 2024/07/02 13:22:02 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"

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