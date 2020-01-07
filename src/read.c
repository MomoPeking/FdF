/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:12:20 by qdang             #+#    #+#             */
/*   Updated: 2020/01/04 17:45:26 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_point_number(int fd)
{
	char	*line;
	int		pn;

	pn = 0;
	while (get_next_line(fd, &line) == 1)
	{
		pn += ft_wordcount(line);
		free(line);
	}
	return (pn);
}

static void		get_info(t_fdf *fdf, int sn, int row, int i)
{
	fdf->info[sn].x = i;
	fdf->info[sn].y = row;
	if (fdf->info[sn].z > fdf->z_high)
		fdf->z_high = fdf->info[sn].z;
	if (fdf->info[sn].z < fdf->z_low)
		fdf->z_low = fdf->info[sn].z;
}

static int		store_line_point(char *line, int row, t_fdf *fdf, int sn)
{
	char	**content;
	char	**temp;
	int		i;

	i = 0;
	content = ft_strsplit(line, ' ');
	while (content[i])
	{
		temp = ft_strsplit(content[i], ',');
		get_info(fdf, sn, row, i);
		fdf->info[sn].z = ft_atoi(temp[0]);
		if (temp[1])
			fdf->point[sn].color = ft_atoihex(temp[1]);
		else
			fdf->point[sn].color = 0;
		free(content[i]);
		free(temp[0]);
		free(temp[1]);
		free(temp);
		sn++;
		i++;
	}
	free(content);
	return (sn);
}

static t_fdf	*store_all_point(int fd, t_fdf *fdf)
{
	char	*line;
	int		row;
	int		sn;

	row = 0;
	sn = 0;
	while (get_next_line(fd, &line) == 1)
	{
		sn = store_line_point(line, row, fdf, sn);
		free(line);
		row++;
	}
	fdf->col = fdf->pn / row;
	return (fdf);
}

t_fdf			*read_and_store(char *file)
{
	int		fd;
	int		pn;
	t_fdf	*fdf;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("The input file is invalid.\n");
		exit(0);
	}
	pn = get_point_number(fd);
	close(fd);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->info = (t_info *)malloc(sizeof(t_info) * pn);
	fdf->point = (t_point *)malloc(sizeof(t_point) * pn);
	fdf->pn = pn;
	fdf->z_high = 0;
	fdf->z_low = 0;
	fd = open(file, O_RDONLY);
	fdf = store_all_point(fd, fdf);
	return (fdf);
}
