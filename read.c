/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:41:14 by qdang             #+#    #+#             */
/*   Updated: 2019/12/31 10:17:55 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_point_number(int fd)
{
	char	*line;
	int		pn;

	pn = 0;
	while (get_next_line(fd, &line) == 1)
		pn += ft_wordcount(line);
	return (pn);
}

static int		store_line_point(char *line, int row, t_point **store, int s_nb)
{
	char	**content;
	char	**temp;
	int		i;

	i = 0;
	content = ft_strsplit(line, ' ');
	while (*content)
	{
		temp = ft_strsplit(*content, ',');
		(*store)[s_nb].x = (double)i;
		(*store)[s_nb].y = (double)row;
		(*store)[s_nb].z = (double)ft_atoi(temp[0]);
		if ((*store)[s_nb].z > (*store)[0].zhigh)
			(*store)[0].zhigh = (*store)[s_nb].z;
		if ((*store)[s_nb].z < (*store)[0].zlow)
			(*store)[0].zlow = (*store)[s_nb].z;
		if (temp[1])
			(*store)[s_nb].color = ft_atoihex(temp[1]);
		else
			(*store)[s_nb].color = 0;
		content++;
		s_nb++;
		i++;
	}
	return (s_nb);
}

static t_point	*store_all_point(int fd, int pn)
{
	t_point	*store;
	char	*line;
	int		row;
	int		s_nb;
	int		i;

	row = 0;
	s_nb = 0;
	i = -1;
	store = (t_point *)malloc(sizeof(t_point) * pn);
	store[0].zhigh = 0;
	store[0].zlow = 0;
	while (get_next_line(fd, &line) == 1)
	{
		s_nb = store_line_point(line, row, &store, s_nb);
		row++;
	}
	store[0].col = pn / row;
	return (store);
}

t_point			*read_and_store(char *file)
{
	int		fd;
	int		pn;
	int		i;
	t_point	*store;

	i = -1;
	fd = open(file, O_RDONLY);
	pn = get_point_number(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	store = store_all_point(fd, pn);
	store[0].pn = pn;
	return (store);
}
