/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:56:21 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/13 09:21:45 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* Return how many line are in the map */
/* and save how many colums has the mape in o_map->colum */
int	counts(int fd, int count_lines, int count_col, t_map *o_map)
{
	int		size;
	char	buffer;

	while (true)
	{
		size = read(fd, &buffer, 1);
		if (size < 0)
			return (errors("failed int the read of file"));
		verify(check(buffer, o_map, count_col, count_lines), o_map);
		if (buffer == '\n')
			count_lines++;
		else if (buffer != '\n' && size > 0)
			count_col++;
		if (o_map->end_col == 0 && buffer == '\n')
			o_map->end_col = count_col - 1;
		if (o_map->end_col != count_col - 1 && (buffer == '\n' || size == 0))
			return (errors("map has less coluns in some lines"));
		else if (buffer == '\n')
			count_col = 0;
		if (size == 0)
			break ;
	}
	o_map->colum = o_map->end_col + 1;
	return (count_lines);
}

/* Return How many lines has the map */
int	lines(char *map, t_map *o_map)
{
	int		fd;
	int		count_lines;
	int		count_col;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (errors("erro for open the file"));
	count_lines = 1;
	count_col = 0;
	count_lines = counts(fd, count_lines, count_col, o_map);
	if (count_lines <= 0)
		return (errors("has some error in the map"));
	close(fd);
	return (count_lines);
}

/* Allocates n space in the memory for a array with the count lines from map */
static char	**alloc_map(char *path, t_map *o_map)
{
	char	**map_str;

	o_map->line = lines(path, o_map);
	if (o_map->valid <= 0)
		return (null_erro("invalid map"));
	if (o_map->line <= 0)
		return (null_erro("has some error in the map"));
	map_str = malloc(sizeof(char *) * o_map->line + 1);
	if (!map_str)
		return (null_erro("error in the allocation memory of the map"));
	return (map_str);
}

static void	check_last_line(char *line, t_map *map)
{
	int	i;
	int	cpe;

	i = 0;
	while (i < map->end_col)
	{
		if (line[i] == '1')
			i++;
		else
		{
			map->valid = 0;
			break ;
		}
	}
	cpe = valid_cpe(map);
	if (cpe == 0)
		map->valid = 0;
}

/* fill the array with the map 2d */
char	**read_map(char *path, t_map *o_map)
{
	int		fd;
	int		i;
	char	**map_str;

	map_str = alloc_map(path, o_map);
	if (!map_str)
		return (null_erro("error in the allocation memory of the map"));
	fd = open(path, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map_str[i++]))
		;
	map_str[i] = NULL;
	check_last_line(map_str[i - 1], o_map);
	if (o_map->valid == 0)
	{
		free_map(map_str, o_map);
		return (null_erro("invalid map"));
	}
	backup_map(o_map, map_str);
	close(fd);
	return (map_str);
}
