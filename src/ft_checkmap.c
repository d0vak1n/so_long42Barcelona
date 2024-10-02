/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:12:21 by ramoreno          #+#    #+#             */
/*   Updated: 2024/10/02 19:34:38 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include <stdio.h>

static void	_map_error(char *str)
{
	ft_write(str);
	exit(1);
}

static int	_check_size(int fd)
{
	char	*line;
	int		prev_x;
	int		x;
	int		y;

	x = 0;
	y = 0;
	line = get_next_line(fd);
	if (!line)
		_map_error("Error\nEmpty file\n");
	prev_x = ft_strlen(line);
	while (line)
	{
		y++;
		x = ft_strlen(line);
		if (x != prev_x)
			_map_error("Error\nMap is not rectangular\n");
		prev_x = x;
		line = get_next_line(fd);
	}
	if (x <= y)
		_map_error("Error\nMap is not rectangular: height >= width\n");
	else
		return (0);
	return (1);
}

static int	_check_walls(int fd)
{
	char	*line;
	char	*prev_line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		_map_error("Error\nEmpty file\n");
	while (line[++i]) // Priemra linea
	{
		if (line[i] != '1')
			_map_error("Error\nMap is not surrounded by walls1");
	}
	while (line) //Segunda linea
	{
		prev_line = line;
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			ft_write("toma toma2\n");
		line = get_next_line(fd);
	}
	i = -1;
	while (prev_line[++i]) // ultima linea
	{
		if (line[i] != '1')
			_map_error("Error\nMap is not surrounded by walls3");
	}
	return (0);
}

int	ft_checkmap(char *f)
{
	int	fd;

	fd = open(f, O_RDONLY);
	if (fd == -1)
		_map_error("Error\nFile not found\n");
	if (_check_size(fd) == 0)
	{
		fd = open(f, O_RDONLY);
		if (_check_walls(fd) == 0)
			_map_error("Map is surrounded by walls\n");
	}
	else
		_map_error("Error\nMap is not rectangular\n");
	return (1);
}
