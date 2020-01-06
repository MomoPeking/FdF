/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:50:41 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 19:50:43 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				line_color_xne(t_point p1, t_point p2, int i)
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

int				line_color_yne(t_point p1, t_point p2, int i)
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

int				line_color_xe(t_point p1, t_point p2, int i)
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

static t_color	*color_hpl(t_color *color)
{
	color->hr = HIGH / 65536;
	color->hg = HIGH / 256 - color->hr * 256;
	color->hb = HIGH % 256;
	color->pr = PLAIN / 65536;
	color->pg = PLAIN / 256 - color->pr * 256;
	color->pb = PLAIN % 256;
	color->lr = LOW / 65536;
	color->lg = LOW / 256 - color->lr * 256;
	color->lb = LOW % 256;
	return (color);
}

int				color_transpoint(int a1, int a2, char c)
{
	int		r;
	int		g;
	int		b;
	t_color	*color;
	double	k;

	color = (t_color *)malloc(sizeof(t_color));
	color = color_hpl(color);
	k = (double)a1 / (double)a2;
	if (c == 'H')
	{
		r = ft_dtoi(color->pr + (color->hr - color->pr) * k);
		g = ft_dtoi(color->pg + (color->hg - color->pg) * k);
		b = ft_dtoi(color->pb + (color->hb - color->pb) * k);
	}
	if (c == 'L')
	{
		r = ft_dtoi(color->pr + (color->lr - color->pr) * k);
		g = ft_dtoi(color->pg + (color->lg - color->pg) * k);
		b = ft_dtoi(color->pb + (color->lb - color->pb) * k);
	}
	free(color);
	return (r * 65536 + g * 256 + b);
}
