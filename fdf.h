/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:46:17 by qdang             #+#    #+#             */
/*   Updated: 2019/12/28 20:55:20 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define PI acos(-1)

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	int		row;
	int		pn;
}				t_point;

t_point			*read_and_store(char *file);

t_point	*rotation_ccw_x(t_point *store, double angle);
t_point	*rotation_ccw_y(t_point *store, double angle);
t_point	*rotation_ccw_z(t_point *store, double angle);

#endif
