/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_so_long.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:44:13 by ramoreno          #+#    #+#             */
/*   Updated: 2024/05/06 12:44:18 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SO_LONG_H
# define LIB_SO_LONG_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
void	lgtbi(t_data *data, int x, int y);
#endif