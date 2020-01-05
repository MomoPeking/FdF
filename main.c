/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:20:53 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 16:49:49 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		key_press(int keycode, t_point *store)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT)
	{
		store = move(store, 10, 0, 0);
		draw_all(store);
	}
	if (keycode == LEFT)
	{
		store = move(store, -10, 0, 0);
		draw_all(store);
	}
	if (keycode == UP)
	{
		store = move(store, 0, -10, 0);
		draw_all(store);
	}
	if (keycode == DOWN)
	{
		store = move(store, 0, 10, 0);
		draw_all(store);
	}
	if (keycode == P)
	{
		store = move(store, 0, 10, 0);
		draw_all(store);
	}


	return (0);
}

t_point	*init_set(t_point *store)
{
	store = color_set(store);
	store = color_calculate(store);
	store = rotation_x(store, -0.5);
	store = rotation_y(store, 0.5);
	store = rotation_z(store, -0.5);
	store = enlarge(store, 30, 30, 30);
	store = move(store, 500, 250, 250);
	return (store);
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
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "FdF");
	store[0].mlx_ptr = mlx_ptr;
	store[0].win_ptr = win_ptr;
//	store = enlarge(store, 10, 10, 4);
	store = init_set(store);
	draw_all(store);
	mlx_key_hook(win_ptr, key_press, store);
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
