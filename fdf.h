/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:46:17 by qdang             #+#    #+#             */
/*   Updated: 2019/12/31 10:17:57 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define	WHITE	0XFFFFFF
# define	LIME	0X00FF00
# define	RED		0XFF0000

# define	HIGH	WHITE
# define	PLAIN	LIME
# define	LOW		RED

# define	HR		HIGH / 65536
# define	HG		HIGH / 256 - HR * 256
# define	HB		HIGH % 256

# define	PR		PLAIN / 65536
# define	PG		PLAIN / 256 - PR * 256
# define	PB		PLAIN % 256

# define	LR		LOW / 65536
# define	LG		LOW / 256 - LR * 256
# define	LB		LOW % 256


typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	int		zhigh;
	int		zlow;
	int		intx;
	int		inty;
	int		color;
	int		red;
	int		green;
	int		blue;
	int		col;
	int		pn;
}				t_point;

t_point			*read_and_store(char *file);

t_point			*rotation_x(t_point *store, double angle);
t_point			*rotation_y(t_point *store, double angle);
t_point			*rotation_z(t_point *store, double angle);
t_point			*enlarge(t_point *store, int xt, int yt, int zt);
t_point			*move(t_point *store, int xd, int yd, int zd);

int				line_color_xne(t_point p1, t_point p2, int i);
int				line_color_yne(t_point p1, t_point p2, int i);
int				line_color_xe(t_point p1, t_point p2, int i);

t_point			*xy_to_int(t_point *store);
void			draw_line(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2);

#endif
