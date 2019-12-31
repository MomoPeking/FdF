/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:20:53 by qdang             #+#    #+#             */
/*   Updated: 2019/12/31 10:45:06 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_point	*color_calculate(t_point *store)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].red = store[i].color / 65536;
		store[i].green = store[i].color / 256 - store[i].red * 256;
		store[i].blue = store[i].color % 256;
	}
	return (store);
}

int		color_zlow(int k)
{
	int		r;
	int		g;
	int		b;

	r = LR + (PR - LR) * k;
	g = LG + (PG - LG) * k;
	b = LB + (PB - LB) * k;
	return (r * 65536 + g * 256 + b);
}

int		color_zhigh(int k)
{
	int		r;
	int		g;
	int		b;

	r = PR + (HR - PR) * k;
	g = PG + (HG - PG) * k;
	b = PB + (HG - PB) * k;
	return (r * 65536 + g * 256 + b);
}

t_point	*color_set(t_point *store)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		if (store[i].color == 0)
		{
			if (store[i].z == 0)
				store[i].color = PLAIN;
			else if (store[i].z > 0)
				store[i].color = color_zhigh(store[i].z / store[0].zhigh);
			else
				store[i].color = color_zlow(store[i].z / store[0].zlow);
		}
	}
	return (store);
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
	store = enlarge(store, 10, 10, 4);
	store = rotation_x(store, -0.5);
	store = rotation_y(store, 0.5);
	store = rotation_z(store, -0.5);
	store = enlarge(store, 2, 2, 2);
	store = move(store, 500, 250, 250);
	store = xy_to_int(store);
	while (++i < store[0].pn)
	{
		if (i % store[0].col < store[0].col - 1)
			draw_line(mlx_ptr, win_ptr, store[i], store[i + 1]);
		if (i < store[0].pn - store[0].col)
			draw_line(mlx_ptr, win_ptr, store[i], store[i + store[0].col]);
	}
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
		printf("%d\n", store[0].zhigh);
		printf("%d\n", store[0].zlow);
		printf("%d %d %d\n", HR, HG, HB);
		printf("%d %d %d\n", PR, PG, PB);
		printf("%d %d %d\n", LR, LG, LB);
//		while (++i < store[0].pn)
//		   printf("{x:%f, y:%f, z:%f}\n", store[i].x, store[i].y, store[i].z);
		window(store);
	}
	else
		ft_putstr("Please input a map.\n");
	return (0);
}
