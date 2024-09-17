/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:50:22 by ramoreno          #+#    #+#             */
/*   Updated: 2024/09/17 17:50:25 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_so_long.h"
#include <unistd.h>
#include "../libft/libft.h"

int	_ft_print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	if (len == -1)
		return (-1);
	else
		return (len);
}

int	ft_write(char *str)
{
	int	len;
	int	i;
	int	err;

	i = -1;
	len = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[++i])
	{
		err = 0;
		err += _ft_print_char(str[i]);
		if (err == -1)
			return (-1);
		else
			len += err;
	}
	return (len);
}
