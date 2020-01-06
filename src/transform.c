/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:38:50 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 18:38:52 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*rotation(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->pn)
	{
		fdf->point[i].y =
			fdf->point[i].y * cos(fdf->x_rt) + fdf->point[i].z * sin(fdf->x_rt);
		fdf->point[i].z =
			fdf->point[i].z * cos(fdf->x_rt) - fdf->point[i].y * sin(fdf->x_rt);
		fdf->point[i].x =
			fdf->point[i].x * cos(fdf->y_rt) - fdf->point[i].z * sin(fdf->y_rt);
		fdf->point[i].z =
			fdf->point[i].z * cos(fdf->y_rt) + fdf->point[i].x * sin(fdf->y_rt);
		fdf->point[i].x =
			fdf->point[i].x * cos(fdf->z_rt) + fdf->point[i].y * sin(fdf->z_rt);
		fdf->point[i].y =
			fdf->point[i].y * cos(fdf->z_rt) - fdf->point[i].x * sin(fdf->z_rt);
	}
	return (fdf);
}

t_fdf	*move(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->pn)
	{
		fdf->point[i].x += fdf->x_move;
		fdf->point[i].y += fdf->y_move;
	}
	return (fdf);
}

t_fdf	*enlarge(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->pn)
	{
		fdf->point[i].x *= fdf->xy_times;
		fdf->point[i].y *= fdf->xy_times;
		fdf->point[i].z *= fdf->z_times;
	}
	return (fdf);
}

t_fdf	*to_int(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->pn)
	{
		fdf->point[i].x_int = ft_dtoi(fdf->point[i].x);
		fdf->point[i].y_int = ft_dtoi(fdf->point[i].y);
	}
	return (fdf);
}
