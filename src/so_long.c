/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 00:15:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/10 23:46:58 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void start_map(t_map *map)
{
	map->colum = 0;
	map->line = 0;
}

int main(int argc, char **argv)
{
	t_map map;
	map.colum = 0;
	map.line = 0;
	map.valid = 1;
	map.end_col = 0;
	int fd = open("map_files/map.ber", O_RDONLY);
	printf("FD MAIN: %i\n", fd);
	//int line = lines("map_files/map.ber", &map);
	map.map = read_map("map_files/map.ber", &map);
//	if (map.map == NULL)
//		return (-1);
	if (map.map)
	{
		printf("LINHAS: %i COLUM: %i\n", map.line, map.colum);
		int i = 0;
		while (i < map.line)
			printf("%s\n", map.map[i++]);
		i = 0;
		while (i <= map.line)
			free(map.map[i++]);
		free(map.map);
	}
	close(fd);
	return (0);
}