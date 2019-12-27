/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:20:53 by qdang             #+#    #+#             */
/*   Updated: 2019/12/26 19:56:30 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	window()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "FdF");
	mlx_loop(mlx_ptr);
}

int		main(int ac, char **av)
{
	t_point	*store;

	int		i;
	
	i = -1;
	if (ac == 2)
	{
		store = read_and_store(av[1]);
		while (++i < store[0].pn)
		   printf("{x:%d, y:%d, z:%d}\n", store[i].x, store[i].y, store[i].z);
	//	window();
	}
	else
		ft_putstr("Please input a map.\n");
	return (0);
}
