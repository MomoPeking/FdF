/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:29:03 by qdang             #+#    #+#             */
/*   Updated: 2020/01/05 22:49:26 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(t_fdf *fdf)
{
	free(fdf->info);
	free(fdf->point);
	free(fdf);
	exit(0);
}

static int	key_press(int key, t_fdf *fdf)
{
	if (key == ESC)
		close_window(fdf);
	if (key == RIGHT)
		fdf->x_move += 10;
	if (key == LEFT)
		fdf->x_move -= 10;
	if (key == UP)
		fdf->y_move -= 10;
	if (key == DOWN)
		fdf->y_move += 10;
	if (key == H)
		fdf->z_times += 1;
	if (key == L)
		fdf->z_times -= 1;
	if (key == B)
		fdf->xy_times += 1;
	if (key == S)
		fdf->xy_times -= 1;
	if (key == P)
		fdf = parallel_set(fdf);
	if (key == I)
		fdf = iso_set(fdf);
	draw_all(fdf);
	return (0);
}

void		scene(t_fdf *fdf)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	i = -1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "FdF");
	fdf->mlx_ptr = mlx_ptr;
	fdf->win_ptr = win_ptr;
	fdf = start_set(fdf);
	fdf = iso_set(fdf);
	draw_all(fdf);
	mlx_key_hook(win_ptr, key_press, fdf);
	mlx_hook(win_ptr, 17, 0, close_window, fdf);
	mlx_loop(mlx_ptr);
}
