/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 09:18:38 by qdang             #+#    #+#             */
/*   Updated: 2020/01/05 10:29:07 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*point_set(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->pn)
	{
		fdf->point[i].x = (double)fdf->info[i].x;
		fdf->point[i].y = (double)fdf->info[i].y;
		fdf->point[i].z = (double)fdf->info[i].z;
	}
	return (fdf);
}

t_fdf	*color_set(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->pn)
	{
		if (fdf->point[i].color == 0)
		{
			if (fdf->info[i].z >= 0)
				fdf->point[i].color =
					color_transpoint(fdf->info[i].z, fdf->z_high, 'H');
			else
				fdf->point[i].color =
					color_transpoint(fdf->info[i].z, fdf->z_low, 'L');
		}
		fdf->point[i].red = fdf->point[i].color / 65536;
		fdf->point[i].green =
			fdf->point[i].color / 256 - fdf->point[i].red * 256;
		fdf->point[i].blue = fdf->point[i].color % 256;
	}
	return (fdf);
}

t_fdf	*iso_set(t_fdf *fdf)
{
	fdf->x_rt = -0.5;
	fdf->y_rt = 0.5;
	fdf->z_rt = -0.5;
	fdf->x_move = 500;
	fdf->y_move = 250;
	fdf->xy_times = 30;
	fdf->z_times = 10;
	return (fdf);
}

t_fdf	*parallel_set(t_fdf *fdf)
{
	fdf->x_rt = 0;
	fdf->y_rt = 0;
	fdf->z_rt = 0;
	fdf->x_move = 500;
	fdf->y_move = 250;
	fdf->xy_times = 30;
	fdf->z_times = 0;
	return (fdf);
}