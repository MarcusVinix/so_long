/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:56:21 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/10 16:21:00 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* Return how many line are in the map */
/* and save how many colums has the mape in o_map->colum */
int	counts(int fd, int count_lines, int count_col, t_map *o_map)
{
	int		size;
	char	buffer;
	int tmp;

	tmp = 0;	
	while (true)
	{
		size = read(fd, &buffer, 1);
		printf("size: %i\n", size);
		if (size < 0)
			return (errors("failed int the read of file"));			
		if (buffer == '\n')
			count_lines++;
		else if (buffer != '\n' && size > 0)
			count_col++;
		if (tmp == 0 && buffer == '\n')
			tmp = count_col;
		printf("TMP: %i COLUM: %i\n", tmp, count_col);
		if (tmp != count_col && (buffer == '\n' || size == 0))
			return (errors("map has less coluns in some lines"));
		else if (buffer == '\n')
			count_col = 0;
		if (size == 0)
			break ;
	}
	o_map->colum = tmp;
	return (count_lines);
}

/* Return How many lines has the map */
int	lines(char *map, t_map *o_map)
{
	int		fd;
	int		count_lines;
	int		count_col;
	
	fd = open(map, O_RDONLY);
	printf("FD: %i\n", fd);
	if (fd < 0)
		return (errors("erro for open the file"));
	count_lines = 1;
	count_col = 0;
	printf("FD: %i  %i\n", fd, count_lines);
	count_lines = counts(fd, count_lines, count_col, o_map);
	printf("COLUM: %i LIne: %i\n", o_map->colum, count_lines);
	if (count_lines <= 0)
		return (errors("has some error in the map"));
	close(fd);
	return (count_lines);
}

/* Allocates n space in the memory for a array with the count lines from map */
char	**alloc_map(char *path, t_map *o_map)
{
	char	**map_str;

	o_map->line = lines(path, o_map);
	if (o_map->line <= 0)
		return (null_erro("has some error in the map"));
	map_str = malloc(sizeof(char *) * o_map->line + 1);
	if (!map_str)
		return (null_erro("error in the allocation memory of the map"));
	return (map_str);
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
	while (get_next_line(fd, &map_str[i++]));
	map_str[i] = NULL;
	close(fd);
	return (map_str);
}
