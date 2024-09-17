/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:12:21 by ramoreno          #+#    #+#             */
/*   Updated: 2024/09/17 18:01:19 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include <stdio.h>

int	_check_size(int fd)
{
	char	*line;
	int		prev_x;
	int		x;
	int		y;

	x = 0;
	y = 0;
	line = get_next_line(fd);
	y++;
	x = ft_strlen(line);
	while ((line = get_next_line(fd)))
	{
		y++;
		prev_x = x;
		x = ft_strlen(line);
		printf("x: %d, prev_x: %d\n", x, prev_x);
		printf("y: %d\n", y);
		if (x != prev_x)
		{
			ft_write("Error\nMap is not rectangular\n");
			return (0);
		}
	}
	if (x < y)
	{
		ft_write("Error\nMap is not rectangular\n");
		return (0);
	}
	return (1);
}

int	ft_checkmap(char* f)
{
	int fd = open(f, O_RDONLY);
	if (fd == -1)
	{
		ft_write("Error\nFile not found\n");
		return (1);
	}
	if (_check_size(fd) != 0)
	{
		ft_write("Nice!\nMap is rectangular\n");
		return (1);
	}
	else
	{
		ft_write("Error\nMap is not rectangular\n");
		return (1);
	}
}

