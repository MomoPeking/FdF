/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:20:53 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 15:05:23 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		key_press(int keycode, void *store)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT)
	{
		


		store = move(store, 10, 0, 0);
	}
	return (0);
}

int		close_window(void *store)
{
	(void)store;
	exit(0);
	return (0);
}

void	window(t_point *store)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	i = -1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "FdF");
	store = color_set(store);
	store = color_calculate(store);
	mlx_key_hook(win_ptr, key_press, store);


//	store = enlarge(store, 10, 10, 4);
	store = rotation_x(store, -0.5);
	store = rotation_y(store, 0.5);
	store = rotation_z(store, -0.5);
	store = enlarge(store, 20, 20, 20);
	store = move(store, 500, 250, 250);
	store = xy_to_int(store);
	while (++i < store[0].pn)
	{
		if (i % store[0].col < store[0].col - 1)
			draw_line(mlx_ptr, win_ptr, store[i], store[i + 1]);
		if (i < store[0].pn - store[0].col)
			draw_line(mlx_ptr, win_ptr, store[i], store[i + store[0].col]);
	}


	mlx_hook(win_ptr, 17, 0, close_window, store);
	mlx_loop(mlx_ptr);
}

int		main(int ac, char **av)
{
	int		i;
	t_point	*store;

	i = -1;
	if (ac == 2)
	{
		store = read_and_store(av[1]);
//		while (++i < store[0].pn)
//		   printf("{x:%f, y:%f, z:%f}\n", store[i].x, store[i].y, store[i].z);
		window(store);
	}
	else
		ft_putstr("Please input a map.\n");
	return (0);
}
