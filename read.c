/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:41:14 by qdang             #+#    #+#             */
/*   Updated: 2019/12/28 16:23:23 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_point_number(int fd)
{
	char	*line;
	int		point_number;

	point_number = 0;
	while (get_next_line(fd, &line) == 1)
		point_number += ft_wordcount(line);
	return (point_number);
}

static int		store_line_point(char *line, int y, t_point **store, int s_nb)
{
	char	**temp;
	int		store_z[ft_wordcount(line)];
	int		i;
	int		j;

	i = 0;
	temp = ft_strsplit(line, ' ');
	while (*temp)
	{
		store_z[i] = ft_atoi(*temp);
		temp++;
		i++;
	}
	j = 0;
	while (j < i)
	{
		(*store)[s_nb].x = (double)j * 5;
		(*store)[s_nb].y = (double)y * 5;
		(*store)[s_nb].z = (double)store_z[j];
		j++;
		s_nb++;
	}
	return (s_nb);
}

static t_point	*store_all_point(int fd, int point_number)
{
	t_point	*store;
	char	*line;
	int		y;
	int		s_nb;
	int		i;

	y = 0;
	s_nb = 0;
	i = -1;
	store = (t_point *)malloc(sizeof(t_point) * point_number);
	while (get_next_line(fd, &line) == 1)
	{
		s_nb = store_line_point(line, y, &store, s_nb);
		y++;
	}
	while (++i < point_number)
		store[i].row = y;
	return (store);
}

t_point 		*read_and_store(char *file)
{
	int		fd;
	int		point_number;
	int		i;
	t_point	*store;

	i = -1;
	fd = open(file, O_RDONLY);
	point_number = get_point_number(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	store = store_all_point(fd, point_number);
	while (++i < point_number)
		store[i].pn = point_number;
	return (store);
}
