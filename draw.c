/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:34:27 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 18:34:31 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void		draw_line_lx(t_fdf *fdf, t_point p1, t_point p2)
{
	int		i;
	double	k;

	i = -1;
	k = (p2.y - p1.y) / (p2.x - p1.x);
	if (p2.x > p1.x)
		while (++i <= p2.x_int - p1.x_int)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.x_int + i,
					ft_dtoi(p1.y + i * k), line_color_xne(p1, p2, i));
	else
		while (++i <= p1.x_int - p2.x_int)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p2.x_int + i,
					ft_dtoi(p2.y + i * k), line_color_xne(p1, p2, i));
}

static void		draw_line_ly(t_fdf *fdf, t_point p1, t_point p2)
{
	int		i;
	double	k;

	i = -1;
	k = (p2.x - p1.x) / (p2.y - p1.y);
	if (p2.y > p1.y)
		while (++i <= p2.y_int - p1.y_int)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, ft_dtoi(p1.x + i * k),
					p1.y_int + i, line_color_yne(p1, p2, i));
	else
		while (++i <= p1.y_int - p2.y_int)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, ft_dtoi(p2.x + i * k),
					p2.y_int + i, line_color_yne(p1, p2, i));
}

static void		draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int		i;

	i = -1;
	if (p1.x_int == p2.x_int)
		while (++i <= ft_abs(p1.y_int - p2.y_int))
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.x_int,
					fmin(p1.y_int, p2.y_int) + i, line_color_xe(p1, p2, i));
	else
	{
		if (ft_abs(p2.y_int - p1.y_int) <= ft_abs(p2.x_int - p1.x_int))
			draw_line_lx(fdf, p1, p2);
		else
			draw_line_ly(fdf, p1, p2);
	}
}

void			draw_all(t_fdf *fdf)
{
	int	i;

	i = -1;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf = point_set(fdf);
	fdf = enlarge(fdf);
	fdf = rotation(fdf);
	fdf = move(fdf);
	fdf = to_int(fdf);
	while (++i < fdf->pn)
	{
		if (i % fdf->col < fdf->col - 1)
			draw_line(fdf, fdf->point[i], fdf->point[i + 1]);
		if (i < fdf->pn - fdf->col)
			draw_line(fdf, fdf->point[i], fdf->point[i + fdf->col]);
	}
}