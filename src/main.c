/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:56:08 by qdang             #+#    #+#             */
/*   Updated: 2020/01/05 13:28:48 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		i;
	t_fdf	*fdf;

	i = -1;
	if (ac == 2)
	{
		fdf = read_and_store(av[1]);
		fdf = color_set(fdf);
		scene(fdf);
	}
	else
		ft_putstr("Please input a map.\n");
	return (0);
}
