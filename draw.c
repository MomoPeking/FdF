/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:16:14 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 16:49:45 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*xy_to_int(t_point *store)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].x_int = ft_dtoi(store[i].x);
		store[i].y_int = ft_dtoi(store[i].y);
	}
	return (store);
}

static void		draw_line_lx(void *mlx_ptr, void *win_ptr,
		t_point p1, t_point p2)
{
	int		i;
	double	k;

	i = -1;
	k = (p2.y - p1.y) / (p2.x - p1.x);
	if (p2.x > p1.x)
		while (++i <= p2.x_int - p1.x_int)
			mlx_pixel_put(mlx_ptr, win_ptr, p1.x_int + i,
					ft_dtoi(p1.y + i * k), line_color_xne(p1, p2, i));
	else
		while (++i <= p1.x_int - p2.x_int)
			mlx_pixel_put(mlx_ptr, win_ptr, p2.x_int + i,
					ft_dtoi(p2.y + i * k), line_color_xne(p1, p2, i));
}

static void		draw_line_ly(void *mlx_ptr, void *win_ptr,
		t_point p1, t_point p2)
{
	int		i;
	double	k;

	i = -1;
	k = (p2.x - p1.x) / (p2.y - p1.y);
	if (p2.y > p1.y)
		while (++i <= p2.y_int - p1.y_int)
			mlx_pixel_put(mlx_ptr, win_ptr, ft_dtoi(p1.x + i * k),
					p1.y_int + i, line_color_yne(p1, p2, i));
	else
		while (++i <= p1.y_int - p2.y_int)
			mlx_pixel_put(mlx_ptr, win_ptr, ft_dtoi(p2.x + i * k),
					p2.y_int + i, line_color_yne(p1, p2, i));
}

static void		draw_line(void *mlx_ptr, void *win_ptr,
		t_point p1, t_point p2)
{
	int		i;

	i = -1;
	if (p1.x_int == p2.x_int)
		while (++i <= ft_abs(p1.y_int - p2.y_int))
			mlx_pixel_put(mlx_ptr, win_ptr, p1.x_int,
					fmin(p1.y_int, p2.y_int) + i, line_color_xe(p1, p2, i));
	else
	{
		if (ft_abs(p2.y_int - p1.y_int) <= ft_abs(p2.x_int - p1.x_int))
			draw_line_lx(mlx_ptr, win_ptr, p1, p2);
		else
			draw_line_ly(mlx_ptr, win_ptr, p1, p2);
	}
}

void			draw_all(t_point *store)
{
	int	i;

	i = -1;
	mlx_clear_window(store[0].mlx_ptr, store[0].win_ptr);
	store = xy_to_int(store);
	while (++i < store[0].pn)
	{
		if (i % store[0].col < store[0].col - 1)
			draw_line(store[0].mlx_ptr, store[0].win_ptr,
					store[i], store[i + 1]);
		if (i < store[0].pn - store[0].col)
			draw_line(store[0].mlx_ptr, store[0].win_ptr,
					store[i], store[i + store[0].col]);
	}
}
