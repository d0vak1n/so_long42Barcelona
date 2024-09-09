/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:12:21 by ramoreno          #+#    #+#             */
/*   Updated: 2024/08/16 13:12:24 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <fcntl.h>

int ft_checkmap(char* f)
{
	int fd = open(f, O_RDONLY);
	if (fd == -1)
	{
		ft_write("Error\nFile not found\n");
		return (1);
	}
}
