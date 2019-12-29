/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:20:53 by qdang             #+#    #+#             */
/*   Updated: 2019/12/28 21:32:16 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_point	*enlarge(t_point *store)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].x = store[i].x * 4 + 250;
		store[i].y = store[i].y * 4 + 250;
		store[i].z = store[i].z * 4 + 250;
	}
	return (store);
}

int		round_nb(double nb)
{
	if (nb - (int)nb >= 0.5)
		return ((int)nb + 1);
	else
		return ((int)nb);
}

void	draw_a_line(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2)
{
	int		i;
	double	k;

	i = -1;
	if (round_nb(p1.x) == round_nb(p2.x))
	{
		if (round_nb(p1.y) - round_nb(p2.y) >= 0)
			while (++i <= round_nb(p1.y) - round_nb(p2.y))
				mlx_pixel_put(mlx_ptr, win_ptr, round_nb(p1.x), round_nb(p2.y) + i, 0xFF0000);
		else
			while (++i <= round_nb(p2.y) - round_nb(p1.y))
				mlx_pixel_put(mlx_ptr, win_ptr, round_nb(p1.x), round_nb(p1.y) + i, 0xFF0000);
	}
	else
	{
		k = (p2.y - p1.y) / (p2.x - p1.x);
		if (p2.x > p1.x)
			while (++i <= round_nb(p2.x) - round_nb(p1.x))
				mlx_pixel_put(mlx_ptr, win_ptr, round_nb(p1.x) + i, round_nb(p1.y + i * k), 0xFF0000);
		else	
			while (++i <= round_nb(p1.x) - round_nb(p2.x))
				mlx_pixel_put(mlx_ptr, win_ptr, round_nb(p2.x) + i, round_nb(p2.y + i * k), 0xFF0000);
	}
}

void	window(t_point *store)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		col;

	i = -1;
	col = store[0].pn / store[0].row;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "FdF");
	store = rotation_ccw_x(store, -0.5);
	store = rotation_ccw_y(store, 0.5);
	store = rotation_ccw_z(store, -0.5);
	
//	while (++i < store[0].pn)
//		printf("{x:%f, y:%f, z:%f}\n", store[i].x, store[i].y, store[i].z);


	store = enlarge(store);


	while (++i < store[0].pn)
	{
		if (i % col < col - 1)
			draw_a_line(mlx_ptr, win_ptr, store[i], store[i + 1]);
		if (i < store[0].pn - col)
			draw_a_line(mlx_ptr, win_ptr, store[i], store[i + col]);
	}
	mlx_key_hook(win_ptr, press_esc(53));
	mlx_loop(mlx_ptr);
}





int		press_esc(int esc)
{
	return (-)
}



int		main(int ac, char **av)
{
	t_point	*store;
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
