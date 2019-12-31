/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 23:15:00 by qdang             #+#    #+#             */
/*   Updated: 2019/12/31 01:13:00 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_color_xne(t_point p1, t_point p2, int i)
{
	int		r;
	int		g;
	int		b;

	if (p1.intx <= p2.intx)
	{
		r = p1.red + (p2.red - p1.red) * i / (p2.intx - p1.intx);
		g = p1.green + (p2.green - p1.green) * i / (p2.intx - p1.intx);
		b = p1.blue + (p2.blue - p1.blue) * i / (p2.intx - p1.intx);
	}
	else
	{
		r = p2.red + (p1.red - p2.red) * i / (p1.intx - p2.intx);
		g = p2.green + (p1.green - p2.green) * i / (p1.intx - p2.intx);
		b = p2.blue + (p1.blue - p2.blue) * i / (p1.intx - p2.intx);
	}
	return (r * 65536 + g * 256 + b);
}

int		line_color_yne(t_point p1, t_point p2, int i)
{
	int		r;
	int		g;
	int		b;

	if (p1.inty <= p2.inty)
	{
		r = p1.red + (p2.red - p1.red) * i / (p2.inty - p1.inty);
		g = p1.green + (p2.green - p1.green) * i / (p2.inty - p1.inty);
		b = p1.blue + (p2.blue - p1.blue) * i / (p2.inty - p1.inty);
	}
	else
	{
		r = p2.red + (p1.red - p2.red) * i / (p1.inty - p2.inty);
		g = p2.green + (p1.green - p2.green) * i / (p1.inty - p2.inty);
		b = p2.blue + (p1.blue - p2.blue) * i / (p1.inty - p2.inty);
	}
	return (r * 65536 + g * 256 + b);
}

int		line_color_xe(t_point p1, t_point p2, int i)
{
	int		r;
	int		g;
	int		b;

	if (p1.inty <= p2.inty)
	{
		r = p1.red + (p2.red - p1.red) * i / (p2.inty - p1.inty);
		g = p1.green + (p2.green - p1.green) * i / (p2.inty - p1.inty);
		b = p1.blue + (p2.blue - p1.blue) * i / (p2.inty - p1.inty);
	}
	else
	{
		r = p2.red + (p1.red - p2.red) * i / (p1.inty - p2.inty);
		g = p2.green + (p1.green - p2.green) * i / (p1.inty - p2.inty);
		b = p2.blue + (p1.blue - p2.blue) * i / (p1.inty - p2.inty);
	}
	return (r * 65536 + g * 256 + b);
}
