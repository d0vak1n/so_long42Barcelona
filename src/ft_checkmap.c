/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:12:21 by ramoreno          #+#    #+#             */
/*   Updated: 2024/10/02 16:26:19 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include <stdio.h>

void _map_error(char *str)
{
	ft_write(str);
	exit(1);
}

int	_check_size(int fd)
{
	char *line;
	int prev_x;
	int x;
	int y;

	x = 0;
	y = 0;

	line = get_next_line(fd);
	if (!line)
		_map_error("Error\nEmpty file\n");
	y++;
	x = ft_strlen(line);
	while ((line = get_next_line(fd)))
	{
		y++;
		prev_x = x;
		x = ft_strlen(line);
		printf("x: %d, prev_x: %d, y: %d\n", x, prev_x, y);
		printf("line: %s", line);
		if (x != prev_x)
			_map_error("Error\nMap is not rectangular\n");
	}
	if (x <= y)
		_map_error("Error\nMap is not rectangular\n");
	else
		return (0); //Success
	return (1);
}

int	ft_checkmap(char* f)
{
	int fd = open(f, O_RDONLY);
	if (fd == -1)
		_map_error("Error\nFile not found\n");
	if (_check_size(fd) == 0)
	{
		ft_write("Map is rectangular\n");
		return (0);
	}
	else
		_map_error("Error\nMap is not rectangular\n");
}

