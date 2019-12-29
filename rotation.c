/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:53:10 by qdang             #+#    #+#             */
/*   Updated: 2019/12/28 20:54:33 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*rotation_ccw_x(t_point *store, double angle)
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

t_point	*rotation_ccw_y(t_point *store, double angle)
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

t_point	*rotation_ccw_z(t_point *store, double angle)
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
