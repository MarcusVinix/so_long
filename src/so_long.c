/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 00:15:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 09:03:11 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
	t_game game;
	
	if (init_game(&game, argc, argv) < 0)
		return (0);
	//int fd = open("map_files/map.ber", O_RDONLY);
	//printf("FD MAIN: %i\n", fd);
	//int line = lines("map_files/map.ber", &map);
	//game.map->map = read_map("map_files/map.ber", game.map);
//	if (map.map == NULL)
//		return (-1);
	printf("Entrei\n");
//	t_map map;
//	map.colum = 0;
//	map.line = 0;
//	map.valid = 1;
//	map.end_col = 0;
//	map.check.collect = 0;
//	map.check.exit = 0;
//	map.check.player = 0;
//	game.map = map;
//
//	game.map.map = read_map(argv[1], &game.map);
	if (game.map.map)
	{
		printf("LINHAS: %i COLUM: %i\n", game.map.line, game.map.colum);
		int i = 0;
	
		printf("Entrei");
		while (i < game.map.line)
			printf("%s\n", game.map.map[i++]);
		i = 0;
		while (i <= game.map.line)
			free(game.map.map[i++]);
		free(game.map.map);
	}
	
//	close(fd);
	return (0);
}
