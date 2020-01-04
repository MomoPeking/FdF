/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 23:06:58 by qdang             #+#    #+#             */
/*   Updated: 2020/01/03 23:07:03 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_color_xne(t_point p1, t_point p2, int i)
{
	int		r;
	int		g;
	int		b;

	if (p1.x_int <= p2.x_int)
	{
		r = p1.red + (p2.red - p1.red) * i / (p2.x_int - p1.x_int);
		g = p1.green + (p2.green - p1.green) * i / (p2.x_int - p1.x_int);
		b = p1.blue + (p2.blue - p1.blue) * i / (p2.x_int - p1.x_int);
	}
	else
	{
		r = p2.red + (p1.red - p2.red) * i / (p1.x_int - p2.x_int);
		g = p2.green + (p1.green - p2.green) * i / (p1.x_int - p2.x_int);
		b = p2.blue + (p1.blue - p2.blue) * i / (p1.x_int - p2.x_int);
	}
	return (r * 65536 + g * 256 + b);
}

int		line_color_yne(t_point p1, t_point p2, int i)
{
	int		r;
	int		g;
	int		b;

	if (p1.y_int <= p2.y_int)
	{
		r = p1.red + (p2.red - p1.red) * i / (p2.y_int - p1.y_int);
		g = p1.green + (p2.green - p1.green) * i / (p2.y_int - p1.y_int);
		b = p1.blue + (p2.blue - p1.blue) * i / (p2.y_int - p1.y_int);
	}
	else
	{
		r = p2.red + (p1.red - p2.red) * i / (p1.y_int - p2.y_int);
		g = p2.green + (p1.green - p2.green) * i / (p1.y_int - p2.y_int);
		b = p2.blue + (p1.blue - p2.blue) * i / (p1.y_int - p2.y_int);
	}
	return (r * 65536 + g * 256 + b);
}

int		line_color_xe(t_point p1, t_point p2, int i)
{
	int		r;
	int		g;
	int		b;

	if (p1.y_int <= p2.y_int)
	{
		r = p1.red + (p2.red - p1.red) * i / (p2.y_int - p1.y_int);
		g = p1.green + (p2.green - p1.green) * i / (p2.y_int - p1.y_int);
		b = p1.blue + (p2.blue - p1.blue) * i / (p2.y_int - p1.y_int);
	}
	else
	{
		r = p2.red + (p1.red - p2.red) * i / (p1.y_int - p2.y_int);
		g = p2.green + (p1.green - p2.green) * i / (p1.y_int - p2.y_int);
		b = p2.blue + (p1.blue - p2.blue) * i / (p1.y_int - p2.y_int);
	}
	return (r * 65536 + g * 256 + b);
}
