/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:07:34 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 17:46:47 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx/mlx.h"
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

# define	ESC		53
# define	RIGHT	124
# define	LEFT	123
# define	UP		126
# define	DOWN	125
# define	P		35
# define	I		34
# define	H		4
# define	L		37
# define	B		11
# define	S		1

typedef struct	s_info
{
	int		x;
	int		y;
	int		z;
}				t_info;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	int		x_int;
	int		y_int;
	int		color;
	int		red;
	int		green;
	int		blue;
}				t_point;

typedef struct	s_fdf
{
	t_info	*info;
	t_point	*point;
	void	*mlx_ptr;
	void	*win_ptr;
	int		z_high;
	int		z_low;
	int		col;
	int		pn;
	double	x_rt;
	double	y_rt;
	double	z_rt;
	int		x_move;
	int		y_move;
	int		xy_times;
	int		z_times;
}				t_fdf;

t_fdf			*read_and_store(char *file);

int				line_color_xne(t_point p1, t_point p2, int i);
int				line_color_yne(t_point p1, t_point p2, int i);
int				line_color_xe(t_point p1, t_point p2, int i);
int				color_transpoint(int a1, int a2, char c);

t_fdf			*point_set(t_fdf *fdf);
t_fdf			*color_set(t_fdf *fdf);
t_fdf			*iso_set(t_fdf *fdf);
t_fdf			*parallel_set(t_fdf *fdf);

t_fdf			*rotation(t_fdf *fdf);
t_fdf			*move(t_fdf *fdf);
t_fdf			*enlarge(t_fdf *fdf);
t_fdf			*to_int(t_fdf *fdf);

void			draw_all(t_fdf *fdf);

#endif
