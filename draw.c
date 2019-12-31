/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:16:14 by qdang             #+#    #+#             */
/*   Updated: 2019/12/30 23:37:14 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*xy_to_int(t_point *store)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].intx = ft_dtoi(store[i].x);
		store[i].inty = ft_dtoi(store[i].y);
	}
	return (store);
}

static void	draw_line_lx(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2)
{
	int		i;
	double	k;

	i = -1;
	k = (p2.y - p1.y) / (p2.x - p1.x);
	if (p2.x > p1.x)
		while (++i <= p2.intx - p1.intx)
			mlx_pixel_put(mlx_ptr, win_ptr, p1.intx + i,
					ft_dtoi(p1.y + i * k), line_color_xne(p1, p2, i));
	else
		while (++i <= p1.intx - p2.intx)
			mlx_pixel_put(mlx_ptr, win_ptr, p2.intx + i,
					ft_dtoi(p2.y + i * k), line_color_xne(p1, p2, i));
}

static void	draw_line_ly(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2)
{
	int		i;
	double	k;

	i = -1;
	k = (p2.x - p1.x) / (p2.y - p1.y);
	if (p2.y > p1.y)
		while (++i <= p2.inty - p1.inty)
			mlx_pixel_put(mlx_ptr, win_ptr, ft_dtoi(p1.x + i * k),
					p1.inty + i, line_color_yne(p1, p2, i));
	else
		while (++i <= p1.inty - p2.inty)
			mlx_pixel_put(mlx_ptr, win_ptr, ft_dtoi(p2.x + i * k),
					p2.inty + i, line_color_yne(p1, p2, i));
}

void		draw_line(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2)
{
	int		i;

	i = -1;
	if (p1.intx == p2.intx)
		while (++i <= ft_abs(p1.inty - p2.inty))
			mlx_pixel_put(mlx_ptr, win_ptr, p1.intx,
					fmin(p1.inty, p2.inty) + i, line_color_xe(p1, p2, i));
	else
	{
		if (ft_abs(p2.inty - p1.inty) <= ft_abs(p2.intx - p1.intx))
			draw_line_lx(mlx_ptr, win_ptr, p1, p2);
		else
			draw_line_ly(mlx_ptr, win_ptr, p1, p2);
	}
}
