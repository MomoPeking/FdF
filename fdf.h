/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:46:17 by qdang             #+#    #+#             */
/*   Updated: 2019/12/26 19:53:16 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx/mlx.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_point
{
	int x;
	int	y;
	int	z;
	int	pn;
}				t_point;

t_point			*read_and_store(char *file);

#endif
