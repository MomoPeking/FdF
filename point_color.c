/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 23:07:31 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 14:02:45 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color_transpoint(double k, char c)
{
	int		r;
	int		g;
	int		b;
	
	if (c == 'H')
	{
		r = ft_dtoi(PR + (HR - PR) * k);
		g = ft_dtoi(PG + (HG - PG) * k);
		b = ft_dtoi(PB + (HB - PB) * k);
	}
	if (c == 'L')
	{
		r = ft_dtoi(PR + (LR - PR) * k);
		g = ft_dtoi(PG + (LG - PG) * k);
		b = ft_dtoi(PB + (LB - PB) * k);
	}
	return (r * 65536 + g * 256 + b);
}

t_point		*color_calculate(t_point *store)
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

t_point		*color_set(t_point *store)
{
	int		i;

	i = -1;
	while (++i < store[0].pn)
	{
		if (store[i].color == 0)
		{
			if (store[i].z >= 0)
				store[i].color =
					color_transpoint(store[i].z / store[0].z_high, 'H');
			else
				store[i].color =
					color_transpoint(store[i].z / store[0].z_low, 'L');
		}
	}
	return (store);
}
