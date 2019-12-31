/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:55:53 by qdang             #+#    #+#             */
/*   Updated: 2019/12/30 20:50:17 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*rotation_x(t_point *store, double angle)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].y = store[i].y * cos(angle) + store[i].z * sin(angle);
		store[i].z = store[i].z * cos(angle) - store[i].y * sin(angle);
	}
	return (store);
}

t_point	*rotation_y(t_point *store, double angle)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].x = store[i].x * cos(angle) - store[i].z * sin(angle);
		store[i].z = store[i].z * cos(angle) + store[i].x * sin(angle);
	}
	return (store);
}

t_point	*rotation_z(t_point *store, double angle)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].x = store[i].x * cos(angle) + store[i].y * sin(angle);
		store[i].y = store[i].y * cos(angle) - store[i].x * sin(angle);
	}
	return (store);
}

t_point	*enlarge(t_point *store, int xt, int yt, int zt)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].x = store[i].x * xt;
		store[i].y = store[i].y * yt;
		store[i].z = store[i].z * zt;
	}
	return (store);
}

t_point	*move(t_point *store, int xd, int yd, int zd)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		store[i].x = store[i].x + xd;
		store[i].y = store[i].y + yd;
		store[i].z = store[i].z + zd;
	}
	return (store);
}
